#include "random.h"

void get_dbls(void)
{
   int   i, n;

   printf("\n%s\n%s",
    "Some randomly distributed numbers will be printed.",
    "How many do you want to see?  ");
   scanf("%d", &n);
   for (i = 0; i < n; ++i) {
      if (i % 6 == 0)
       printf("\n");
      printf("%9.3f", probability());
   }
   printf("\n");
}

void get_ints(void)
{
   int   i, n;

   printf("\n%s\n%s",
    "Some randomly distributed integers will be printed.",
    "How many do you want to see?  ");
   scanf("%d", &n);
   for (i = 0; i < n; ++i) {
      if (i % 6 == 0)
       printf("\n");
      printf("%9d", random());
   }
   printf("\n");
}
