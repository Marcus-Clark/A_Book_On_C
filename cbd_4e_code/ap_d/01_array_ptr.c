/*
// ---
// In ANSI C, the address operator & can be applied
// to an array.  In traditional C, many compilers
// will not allow this to be done.
//
// This program illustrates taking the address of
// an array of arrays.
*/

#include <assert.h>
#include <stdio.h>

typedef   const char   cchr;

void   prn_array(cchr* s, int a[][5], int m, int n);

int main(void)
{
   int   a[3][5]      = {{ 2,  3,  5,  7, 11},
                         {13, 17, 19, 23, 29},
                         {31, 37, 41, 43, 47}};
   int   (*p)[][5];

   p = &a;                                   /* not allowed in traditional c */
   putchar('\n');
   prn_array("a", a, 3, 5);
   prn_array("*p", *p, 3, 5);
   return 0;
}

void prn_array(cchr* s, int a[][5], int m, int n)
{
   int   i;
   int   j;

   /*
   // Because the size of the 2nd dimension of the array must
   // be hard-wired, n can only take on the value 5.  Thus there
   // is no need to design the function definition as having two
   // arguments.  However, the call to the function looks more
   // natural if we do so.
   */
   assert(n == 5);
   printf("%s =\n", s);
   for (i = 0; i < m; ++i) {
      printf("  ");
      for (j = 0; j < n; ++j)
         printf("%5d", a[i][j]);
      putchar('\n');
   }
   putchar('\n');
}
