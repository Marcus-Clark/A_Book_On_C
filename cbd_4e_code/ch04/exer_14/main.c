#include "primes.h"

typedef   double   dbl;

const int   forever = 1;

int main(void)
{
   int      cnt, n, x;
   double   val;

   printf("\n%s",
      "PRIME NUMBER THEOREM:\n"
      "\n"
      "     lim    (pi(x) / (x / log(x)) = 1\n"
      "   x -> inf\n"
      "\n"
      "where pi(x) is the number of primes\n"
      "less than or equal to x.\n"
      "\n"
      "How many primes do you want to consider?  ");
   if (scanf("%d", &n) != 1) {
      printf("INPUT ERROR: Bye!\n\n");
      exit(1);
   }
   putchar('\n');
   if (n < 1) {
      printf("Bye!\n\n");
      exit(1);
   }
   /*
   // Print headings.
   */
   printf("%s",
      "     x      pi(x)    pi(x) / (x / log(x))\n"
      "   -----    -----    --------------------\n");
   printf("%s",
      "\n"
      ">> This program needs to be completed.\n"
      ">> Remove this printf() statement and\n"
      ">> supply some 16 lines of code.  See\n"
      ">> the file output to see what the\n"
      ">> output should look like.\n"
      "\n");
   return 0;
}
