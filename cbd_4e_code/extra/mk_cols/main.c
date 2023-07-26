#include "mk_cols.h"

options   o;                                        // options are global

int main(int argc, char** argv)
{
   cchr*      fname;
   int        fwai;                            // first working arg index
   int        nwacl;                    // # of working args on cmnd line
   ifstream   ifs;
   istream*   isp;

   o.get_options(argc, argv);
   fwai = o.get_fwai();
   nwacl = o.get_nwacl();
   assert(fwai > 0);
   assert(nwacl == 0 || nwacl == 1);
   if (nwacl == 1) {
      assert(fwai == argc - 1);
      fname = argv[fwai];
      ifs.open(fname);
      if (!ifs)
         error_exit_cannot_open(fname);
      isp = &ifs;
   }
   else
      isp = &cin;
   mk_cols(isp);
}
