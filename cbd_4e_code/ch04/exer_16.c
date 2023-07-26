#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
   int   cnt_heads = 0, cnt_tails = 0, i, n, val;

   srand(time(NULL));  /* seed the random number generator */
   printf("\n%s",
      "SIMULATED COIN TOSSING:\n"
      "How many times?  ");
   if (scanf("%d", &n) != 1) {
      printf("INPUT ERROR: Bye!\n\n");
      exit(1);
   }
   if (n < 1) {
      printf("Bye!\n\n");
      exit(1);
   }
   for (i = 0; i < n; ++i) {
      val = rand() % 2;
      (val == 1) ? ++cnt_heads : ++cnt_tails;
      if (i % 10 == 0)
         putchar('\n');
      printf("%7s", (val == 1) ? "heads" : "tails");
   }
   printf("\n\n%s%d\n%s%d\n\n",
      "Number of heads: ", cnt_heads,
      "Number of tails: ", cnt_tails);
   return 0;
}
