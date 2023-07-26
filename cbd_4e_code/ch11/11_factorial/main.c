#include "fact.h"

int main(int argc, char ** argv)
{
   int       n;
   Integer   product;

   cout << "\n";
   if (argc == 1 || strncmp(argv[1], "-h", 2) == 0) {
      prn_info(argv[0]);
      exit(1);
   }
   istrstream   iss(argv[1]);
   iss >> n;
   if (!iss) {
      cout << "ERROR: Integer not found - bye!\n\n";
      exit(1);
   }
   if (n < 0) {
      cout << "ERROR: Integer must be nonnegative - bye!\n\n";
      exit(1);
   }
   product = factorial(n);
   prn_factorial(n, product);
}
