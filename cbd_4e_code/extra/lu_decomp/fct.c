#include "lu_decomp.h"

void error_exit_cannot_open(cchr* fname)
{
   cout << "Cannot open " << fname << " - bye!\n\n";
   exit(1);
}

void error_exit_el_not_found(int i, int j, cchr* fname)
{
   cout << "ERROR: el[" << i << "][" << j << "] not found\n"
           "\n"
           "Filename: " << fname << "\n"
           "\n"
           "Bye!\n"
           "\n";
   exit(1);
}

int get_from_cmnd_line(int argc, char** argv)
{
   int   n;
   int   fwai = o.get_fwai();
   
   assert(fwai == argc - 1);
   istrstream iss(argv[fwai]);
   iss >> n;
   if (!iss) {
      cout << "ERROR: n not found - bye!\n\n";
      exit(1);
   }
   if (n < 1) {
      cout << "ERROR: n must be a positive integer - bye!\n\n";
      exit(1);
   }
   return n;
}
