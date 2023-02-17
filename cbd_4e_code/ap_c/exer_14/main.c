#include "try_me.h"

int main(int argc, char** argv)
{
   int   n;

   if (argc > 1 && strcmp(argv[1], "-h") == 0) {
      prn_info(argv[0]);
      exit(1);
   }
   if (argc > 2) {
      cout << "\n"
              "---\n"
              "ERROR: Too many command line arguments.\n";
      prn_info(argv[0]);
      exit(1);
   }
   cout << "\n";
   if (argc == 2) {
      istrstream   iss(argv[1]);
      iss >> n;
      if (!iss) {
         cout << "ERROR: Integer not found - bye!\n\n";
         exit(1);
      }
      run_run(n);
   }
   else {
      for ( ; ; ) {
         cout << "Input an integer: ";
         cin >> n;
         cout << "\n";
         if (!cin) {
            cout << "Bye!\n\n";
            break;
         }
         run_run(n);
      }
   }
}
