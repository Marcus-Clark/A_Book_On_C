#include <iostream.h>
#include <stdlib.h>

int main()
{
   int   i;
   int   m;
   int   n;

   cout << "\n"
           "Some randomly distributed integers will\n"
           "be printed in the interval [0, M].\n"
           "\n"
           "Input M: ";
   cin >> m;
   cout << "\n"
           "How many randomly distributed integers "
           "do you want to see? ";
   cin >> n;
   for (i = 0; i < n; ++i) {
      if (i % 6 == 0)
         cout << "\n";
      cout.width(9);
      cout << rand();
   }
   cout << "\n\nSomething is wrong!\n\n";
   cout << "What happens if you change 9 to 3?\n\n";
}
