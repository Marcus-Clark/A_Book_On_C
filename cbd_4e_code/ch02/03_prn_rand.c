#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int   i, n;

   printf("\n%s\n%s",
    "Some randomly distributed integers will be printed.",
    "How many do you want to see?  ");
   scanf("%d", &n);
   for (i = 0; i < n; ++i) {
      if (i % 6 == 0)
       printf("\n");
      printf("%9d", rand());
   }
   printf("\n");
   return 0;
}
