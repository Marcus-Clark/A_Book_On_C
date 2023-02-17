#include "find_max.h"

int main()
{
   int      a, b;
   double   x, y;

   cout << "\n"
           "Some maximums will be computed.\n"
           "\n"
           "Enter two integers a and b:  ";
   cin >> a >> b;
   cout << "\n"
           "Enter two doubles x and y:  ";
   cin >> x >> y;
   cout << "\n"
           "max(a, b) = " << max(a, b) << ", an int\n"
           "max(x, y) = " << max(x, y) << ", a double\n"
           "\n";
}
