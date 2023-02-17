// ---
// See Section 15.12, "Common Programming Errors" on page 554.

// This code is compiler-dependent.  Many older C++ systems
// can not compile this program.  To see what goes wrong,
// use the -E flag.
//
// Try this program on your system.
//

#include <iostream.h>

#define   LIMIT   77            // danger - watch out!

int main()
{
   int   i;
   int   sum = 0;

   for (i = 1; i <= LIMIT; ++i)
      sum += i;
   cout << "\nsum = " << sum << "\n\n";
}
