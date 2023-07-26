#include <stdio.h>

void   bit_print(int a);

int main(void)
{
   int   k;

   for ( ; ; ) {
      printf("Input an integer:  ");
      if (scanf("%d", &k) != 1)
         break;
      printf("\n%7d = ", k);
      bit_print(k);
      printf("\n\n");
   }
   printf("\nBye!\n\n");
   return 0;
}
