#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int   *a, i, n, sum = 0;

   printf("\n%s",
      "An array will be created dynamically.\n\n"
      "Input an array size n followed by n integers:  ");
   scanf("%d", &n);
   a = calloc(n, sizeof(int));  /* get space for n ints */
   for (i = 0; i < n; ++i)
      scanf("%d", &a[i]);
   for (i = 0; i < n; ++i)
      sum += a[i];
   free(a);                     /* free the space */
   printf("\n%s%7d\n%s%7d\n\n",
      " Number of elements:", n,
      "Sum of the elements:", sum);
   return 0;
}
