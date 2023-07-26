#include <assert.h>
#include <iostream.h>
#include <Integer.h>            // valid for GNU g++

int main()
{
   int       i;
   int       n;
   Integer   product = 1;

   cout << "The factorial of n will be computed.\n"
            "\n"
            "Input n: ";
   cin >> n;
   assert(cin && n >= 0);
   for (i = 2; i <= n; ++i)
      product *= i;
   cout << "\n"
            "factorial(" << n << ") = " << product << "\n"
            "\n";
}
