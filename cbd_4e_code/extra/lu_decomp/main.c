#include "lu_decomp.h"

options   o;                                              // options are global

int main(int argc, char** argv)
{
   int      n;
   int      nwacl;
   dbl      val;
   matrix   a;
   matrix   lu;
   ivec     pv;
   
   clock();                                                  // start the clock
   o.get_options(argc, argv);
   nwacl = o.get_nwacl();
   assert(nwacl == 1);
   n = get_from_cmnd_line(argc, argv);
   a.get_space(n, n);
   lu.get_space(n, n);
   pv.get_space(n);
   if (o.file_option())
      a.fill(o.filename());
   else
      a.fill();
   if (lu_decomp(a, lu, pv) == no) {
      cout << "A =\n"
           << a
           << "\n"
           << "SORRY: The matrix A is singular - bye!\n"
           << "\n";
      exit(1);
   }
   if (!o.norm_only_option()) {
      cout << "A =\n" << a << "\n";
      cout << "LU =\n" << lu << "\n";
      cout << "pv =\n" << pv << "\n\n";
   }
   val = chk(a, lu, pv);
   cout.unsetf(ios::fixed);
   cout.setf(ios::scientific);
   cout.precision(3);
   cout << "norm(A - psy_L * U) = " << val << "\n\n";
   a.release_space();
   lu.release_space();
   pv.release_space();
   if (o.time_option()) {
      dbl   clock_val = clock();
      dbl   runrun    = clock_val / CLOCKS_PER_SEC;
      cout.unsetf(ios::scientific);
      cout.setf(ios::fixed);
      cout.precision(1);
      cout << "---\n"
              "TIME OPTION:\n"
              "   Program running time = " << runrun << "\n"
              "\n";
   }
}
