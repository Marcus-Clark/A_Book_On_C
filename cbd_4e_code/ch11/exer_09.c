/*
// Test the iterative version of the gcd() function.
*/

#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>

int   gcd(int a, int b);

int main(int argc, char** argv)
{
   int   a;
   int   b;

   if (argc == 1 || strncmp(argv[1], "-h", 2) == 0) {
      cout << "\nUsage:  " << argv[0] << "  n1  n2\n\n";
      exit(1);
   }
   istrstream   iss1(argv[1]);
   istrstream   iss2(argv[2]);
   iss1 >> a;
   iss2 >> b;
   if (!iss1 || !iss2) {
      cout << "\nERROR: Integers not found - bye!\n\n";
      exit(1);
   }
   if (a < 1 || b < 1) {
      cout << "\nERROR: Positive integers required - bye!\n\n";
      exit(1);
   }
   cout << "\n   gcd(" << a << ", " << b << ") = " << gcd(a, b) << "\n\n";
}

int gcd(int a, int b)
{
   int   r;

   if ((r = a % b) == 0)
      return b;
   else
      return gcd(b, r);
}
