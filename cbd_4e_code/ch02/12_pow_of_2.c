//
// Some powers of 2 are printed.
//

#include <iostream.h>

int main()
{
   int   i = 0;
   int   n = 29;
   int   power = 1;

   while (++i <= n) {
      cout.width(3);
      cout << i << ": ";
      cout.width(12);
      cout << (power *= 2) << "\n";
   }
   cout << "\n";
   
   cout << "What happens if you remove the "
           "parentheses around power?\n\n";

   cout << "What happens if you change 29 to 33?\n\n";
}
