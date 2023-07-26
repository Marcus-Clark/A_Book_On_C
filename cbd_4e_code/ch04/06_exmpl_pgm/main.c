#include "pgm.h"

int main(void)
{
   char   ans;
   int    k, n = N;

   printf("\n%s",
      "This program does not do very much.\n"
      "\n"
      "Do you want more information?  ");
   scanf(" %c", &ans);
   putchar('\n');
   if (ans == 'y' || ans == 'Y')
      prn_info("pgm");
   for (k = 0; k < n; ++k)
      fct1(k);
   printf("\nBye!\n\n");
   return 0;
}
