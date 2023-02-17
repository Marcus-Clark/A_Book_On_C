#include <fstream.h>       // iostream.h gets included
#include <stdlib.h>

typedef   const char   cchr;

void   dbl_space(ifstream& from, ofstream& to);
void   prn_info(cchr* pgm_name);

int main(int argc, char** argv)
{
   if (argc == 1 || strcmp(argv[1], "-h") == 0 || argc != 3) {
      prn_info(argv[0]);
      exit(1);
   }

   ifstream   ifs(argv[1]);
   ofstream   ofs(argv[2]);

   if (!ifs) {
      cerr << "\nCannot open " << argv[1] << " - bye!\n\n";
      exit(1);
   }
   if (!ofs) {
      cerr << "\nCannot open " << argv[2] << " - bye!\n\n";
      exit(1);
   }
   dbl_space(ifs, ofs);
}

void dbl_space(ifstream& from, ofstream& to)
{
   char   c;

   while (from.get(c)) {
      to.put(c);
      if (c == '\n')
         to.put(c);
   }
}

void prn_info(cchr* pgm_name)
{
   cout << "\n"
           "---\n"
           "Usage:  " << pgm_name << " [-h] infile outfile\n"
           "\n"
           "This program double spaces the contents of infile\n"
           "and writes to outfile.  The infile does not get\n"
           "modified.  The outfile gets created if it does\n"
           "not exist, and it gets overwritten if it does\n"
           "exist.\n"
           "\n"
           "CAUTION: Do not overwrite a file by misake.\n"
           "\n"
           "---\n"
           "Options:\n"
           "   -h   help option, write this message\n"
           "\n";
}
