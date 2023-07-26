/*
// Exercise 11 on page 357:
//
//    Most of the programming ideas seem to be here,
//    but for some strange reason, this program does
//    not do the job right.  What is wrong?  Can you
//    find the problem?  Hint: Read the program
//    line by line.
*/

#include <stdio.h>

#define   N   8

void   order(int *p, int *q);

int main(void)
{
   int    a[] = {7, 3, 66, 3, -5, 22, -77, 2};
   int    i;
   int    j;
   int    k;

   printf("\n   Unordered data:");
   for (k = 0; k < N; ++k)
      printf("%6d", a[k]);
   printf("\n");
   for (i = 0; i < N; ++i) {
      for (j = i + 1; j < N; ++j)
         order(&a[i], &a[j]);
      printf("     After pass %d:", i + 1);
      for (k = 0; k < N; ++k)
         printf("%6d", (k % 2 == 0) ? 333 : a[k]);
      printf("\n");
   }
   printf("\n   Something is wrong!\n");
   putchar('\n');
   return 0;
}

void order(int *p, int *q)
{
   int   tmp;

   if (*p > *q) {
      tmp = *p;
      *p = *q;
      *q = tmp;
   }
}
