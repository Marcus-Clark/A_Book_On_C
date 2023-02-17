#include "palindrome.h"

options   o;                                        // options are global

int main(int argc, char** argv)
{
   cchr*    fname;                                      // input filename
   int      fwai;                              // first working arg index
   int      nwacl;                      // # of working args on cmnd line
   action   a;

   o.get_options(argc, argv);
   fwai = o.get_fwai();
   nwacl = o.get_nwacl();
   assert(fwai == argc - 1);
   assert(nwacl == 1);
   fname = argv[fwai];
   a.get_palindromes(fname);
   a.wrt_palindromes(fname);
}
