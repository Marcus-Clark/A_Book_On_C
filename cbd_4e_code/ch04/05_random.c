#include <stdio.h>
#include <stdlib.h>

int    max(int a, int b);
int    min(int a, int b);
void   prn_random_numbers(int k);

int main(void)
{
   int   n;

   printf("Some random numbers will be printed.\n");
   printf("How many would you like to see?  ");
   scanf("%d", &n);
   prn_random_numbers(n);
   return 0;
}

void prn_random_numbers(int k)
{
   int   i, r, biggest, smallest;

   r = biggest = smallest = rand();
   printf("\n%7d", r);
   for (i = 1; i < k; ++i) {
      if (i % 7 == 0)
         printf("\n");
      r = rand();
      biggest = max(r, biggest);
      smallest = min(r, smallest);
      printf("%7d", r);
   }
   printf("\n\n%s%5d\n%s%5d\n%s%5d\n\n",
      "  Count: ", k,
      "Maximum: ", biggest,
      "Minimum: ", smallest);
}
