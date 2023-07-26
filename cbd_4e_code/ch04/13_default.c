//
// Illustrate default values for a function.
//

#include <iostream.h>

int   sum(int a, int b = 2, int c = 3);     // default values

int main()
{
   cout << "---\n"
           "For the output of this program to make\n"
           "sense, you need to read the code.\n"
           "\n"
           "sum(3)       = " << sum(3)       << "\n"
           "sum(3, 5)    = " << sum(3, 5)    << "\n"
           "sum(3, 5, 7) = " << sum(3, 5, 7) << "\n"
           "\n";
}

int sum(int a, int b, int c)
{
   return a + b + c;
}
