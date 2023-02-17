#include "fortune.h"

void good_bye(cchr* begin_time, int cnt,
              int f_cnt, cchr* ffn, ofstream& ofs)
{
   char         cmnd[maxstring];
   char         end_time[maxstring];
   char         line[maxline];
   char         tfn[maxstring];

   cchr*        subject   = "\"Found a fortune!\"";
   cchr*        user      = ggetenv("USER");

   ifstream     ifs;
   ofstream     tfs;                                         // tmp file stream
   ostrstream   oss;

   //
   // Put a message in a tmp file.
   //
   tmpnam(tfn);
   tfs.open(tfn);
   assert(!!tfs);
   tfs << "Found a fortune!\n"
          "It was saved in the file " << ffn << "\n"
          "\n";
   tfs.close();
   //
   // Send mail to the user.
   //
   oss << "mail -s" << subject << " " << user << " < " << tfn << ends;
   strcpy(cmnd, oss.str());
   gsystem(cmnd);
   get_time(end_time);
   if (o.test_option()) {
      cout << "---\n"
              "TEST OPTION:\n"
              "       cmnd = " << cmnd     << "\n"
              "   end_time = " << end_time << "\n"
              "\n"
              "   ---\n"
              "   Here is the contents of the file " << tfn << ":\n"
              "\n";
      ifs.open(tfn);
      assert(!!ifs);
      while (ifs.getline(line, maxline))
         cout << "   " << line << "\n";
      ifs.close();
   }
   gremove(tfn);
   //
   // Attach a final report to the fortune file.
   //
   ofs << "\n"
          "---\n"
          "Begin time: " << begin_time << "\n"
          "  End time: " << end_time << "\n"
          "\n"
          "---\n"
          "Number of fortunes examined:" << setw(7) <<  cnt << "\n"
          "Number of fortunes saved:" << setw(10) << f_cnt << "\n"
          "\n";
   ofs.close();
   exit(0);                                                      // normal exit
}
