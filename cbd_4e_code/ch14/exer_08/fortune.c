#include "fortune.h"

void find_fortune(cchr* phrase, int n)
{
   char         begin_time[maxstring];
   char         cmnd[maxstring];                                 // for fortune
   char         ffn[maxstring];                             // fortune filename
   char         line[maxline];
   char         wfn[maxstring];                             // working filename
   cchr*        home;

   int          cnt     = 0;
   int          f_cnt   = 0;

   ifstream     ifs;
   ofstream     ofs;
   ostrstream   oss1;
   ostrstream   oss2;

   //
   // Get the beginning time.
   //
   get_time(begin_time);
   //
   // Get the fortune command.
   //
   tmpnam(wfn);
   oss1 << "fortune -a > " << wfn << ends;
   strcpy(cmnd, oss1.str());
   //
   // Get the fortune filename.
   //
   home = ggetenv("HOME");
   oss2 << home << "/tmp_fortune_" << ggetpid() << ends;
   strcpy(ffn, oss2.str());
   //
   // Open the fortune file.
   //
   ofs.open(ffn);
   assert(!!ofs);
   //
   // Print test info.
   //
   if (o.test_option()) {
      cout << "---\n"
              "TEST OPTION:\n"
              "   begin_time = " << begin_time << "\n"
              "         cmnd = " << cmnd       << "\n"
              "         home = " << home       << "\n"
              "          ffn = " << ffn        << "\n"
              "          wfn = " << wfn        << "\n"
              "\n";
   }
   //
   // Find the desired fortunes.
   //
   for ( ; ; ) {
      system(cmnd);                                     // get a fortune in wfn
      ++cnt;
      ifs.open(wfn);                           // get ready to read the fortune
      assert(!!ifs);
      while (ifs.getline(line, maxline)) {
         if (strstr(line, phrase) != NULL) {
            save_fortune(ifs, ofs);             // append what is in wfn to ffn
            ++f_cnt;
            break;
         }
      }
      ifs.close();
      if (f_cnt >= n || cnt > limit)
         break;
   }
   gremove(wfn);
   good_bye(begin_time, cnt, f_cnt, ffn, ofs);               // wrapup and exit
}


void save_fortune(ifstream& ifs, ofstream& ofs)
{
   char   line[maxline];

   ofs << "\n"
          "---\n";
   grewind(ifs);                                   // go to the top of the file
   while (ifs.getline(line, maxline))
      ofs << line << "\n";
}
