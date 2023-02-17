/*
// Compute Fibonacci numbers recursively.
*/

#include <assert.h>
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>

int   fibonacci(int n);

int main(int argc, char** argv)
{
   int   n;

   if (argc == 1 || strncmp(argv[1], "-h", 2) == 0) {
      cout << "\nUsage:  " << argv[0] << "  n\n\n";
      exit(1);
   }
   istrstream   iss(argv[1]);
   iss >> n;
   if (!iss) {
      cout << "\nERROR: Integer not found - bye!\n\n";
      exit(1);
   }
   if (n < 0) {
      cout << "\nERROR: A nonnegative integer is required - bye!\n\n";
      exit(1);
   }
   cout << "\n   fibonacci(" << n << ") = " << fibonacci(n) << "\n\n";
}

int fibonacci(int n)
{
   assert(n >= 0);
   if (n == 0 || n == 1)
      return n;
   return (fibonacci(n - 1) + fibonacci(n - 2));
}
