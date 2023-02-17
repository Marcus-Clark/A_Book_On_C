#include "pgm.h"

int main(void)
{
   char   ans;
   int    i, n = N;

   printf("%s",
      "This program does not do very much.\n"
      "Do you want more information?  ");
   scanf(" %c", &ans);
   if (ans == 'y' || ans == 'Y')
      wrt_info("pgm");
   for (i = 0; i < n; ++i)
      fct1(i);
   printf("Bye!\n");
   return 0;
}
