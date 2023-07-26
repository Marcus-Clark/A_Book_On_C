/*
// If a factorial is comprised of a large number of digits, we
// want to insert a newline character periodically to break up
// the line.  Otherwise, we will get very long lines.
*/

#include "fact.h"

void prn_factorial(int n, Integer & product)
{
   char       c;
   char*      tfn;                                              // tmp filename
   int        cnt;
   ifstream   ifs;
   ofstream   ofs;

   tfn = tmpnam(NULL);                                    // get a tmp filename
   ofs.open(tfn);
   if (!ifs) {
      cout << "\nCannot open " << tfn << " - bye!\n\n";
      exit(1);
   }
   ofs << product;
   ofs.close();
   //
   // If n is small enough, print everything on one line.
   //
   cout << n << "! =" << ((n < 54) ? " " : "\n\n   ");
   cnt = 0;
   ifs.open(tfn);
   ifs.unsetf(ios::skipws);
   while (ifs >> c) {
      cout << c;
      ++cnt;
      if (cnt >= 70) {                 // insert \n chars to prevent long lines
         cout << "\n   ";
         cnt = 0;
      }
   }
   cout << "\n";
   if (cnt > 0)
      cout << "\n";
   ifs.close();
   if (remove(tfn) != 0) {
      cout << "ERROR: Call to remove() failed - bye!\n\n";
      exit(1);
   }
}

void prn_info(cchr* pgm_name)
{
   cout << "---\n"
           "Usage:  " << pgm_name << " [-h]  n\n"
           "\n"
           "The factorial of n is computed.\n"
           "\n"
           "---\n"
           "Options:\n"
           "   -h  help option, print this message\n"
           "\n";
}
