#include "array.h"

int main(void)
{
   int   *a, n;

   srand(time(NULL));     /* seed the random number generator */
   printf("\n%s\n",
      "This program does the following repeatedly:\n"
      "\n"
      "   1  create space for an array of size n\n"
      "   2  fill the array with randomly distributed digits\n"
      "   3  print the array and the sum of its element\n"
      "   4  release the space\n");
   for ( ; ; ) {
      printf("Input n: ");
      if (scanf("%d", &n) != 1 || n < 1)
         break;
      putchar('\n');
      a = calloc(n, sizeof(int));   /* allocate space for a[] */
      fill_array(a, n);
      wrt_array(a, n);
      printf("sum = %d\n\n", sum_array(a, n));
      free(a);
   }
   printf("\nBye!\n\n");
   return 0;
}
