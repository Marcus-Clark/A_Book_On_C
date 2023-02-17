#include <iostream.h>

int main()
{
   int   i, k, m, n, sum = 10, tmp;

   cout << "\n"
           "For integers k, m, and n with k > 1 this program computes\n"
           "the sum of all the integers between m and n that are\n"
           "divisible by k.\n"
           "\n"
           "Input k, m, and n: ";

   cin >> k >> m >> n;

   if (k <= 1) {
      cout << "\nSORRY: k must be positive - bye!\n\n";
      exit(1);
   }
   //
   // Interchange m and n if they are out of order.
   //
   if (m > n) {
      tmp = m;
      m = n;
      n = tmp;
   }
   for (i = m; i <= n; ++i)
      if (k % i == 0)
         sum += i;
   cout << "\n"
           "sum = " << sum << "\n"
           "\n"
           "There are major mistakes in this code.\n"
           "You should find them and correct them.\n"
           "\n";
}
