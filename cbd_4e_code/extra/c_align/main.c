#include "c_align.h"

cchr*     file_extensions = ".c .cc .cp .cpp .cxx .h .hh .hxx "
                            ".C .CC .CP .CPP .CXX .H .HH .HXX";

int       right_edge         = default_right_edge;
options   o;                                        // options are global

main(int argc, char** argv)
{
   char       tfn[maxstring];                             // tmp filename
   char*      fname;
   int        fwai;                            // first working arg index
   int        i;
   int        last_access_time;
   int        last_modify_time;
   ifstream   ifs;
   ofstream   ofs;

   o.get_options(argc, argv);
   //
   // For all filenames check access and filename extension.
   //
   chk_filenames(argc, argv);
   tmpnam(tfn);
   fwai = o.get_fwai();
   for (i = fwai; i < argc; ++i) {
      fname = argv[i];
      get_file_times(fname, last_access_time, last_modify_time);
      //
      // Align comments on the right.
      //
      c_align(fname, tfn);
      if (o.test_option()) {
         view(tfn);
         gremove(tfn);
         if (i < argc - 1)
            cout << "The file " << tfn << " has been removed.\n\n";
         else
            cout << "The file " << tfn << " has been removed - bye!\n\n";
      }
      else {
         copy(tfn, fname);
         restore_file_times(fname, last_access_time, last_modify_time);
         gremove(tfn);
      }
   }
}
