#include "trace.h"

int main(int argc, char **argv)
{
   int   m;                                          /* number of rows */
   int   n;                                       /* number of columns */
   int   val;
   dbl   **a;                                                /* matrix */

   srand(time(NULL));              /* seed the random number generator */
   chk_cmnd_line(argc, argv);
   printf("%s\n",
      "---\n"
      "This program creates space for an mxn matrix A, fills it with\n"
      "randomly distributed digits from -9 to +9, and then prints\n"
      "the matrix A and its trace.\n");
   for ( ; ; ) {
      printf("Input m and n:  ");
      val = scanf("%d%d", &m, &n);
      if (val != 2 || m < 1 || n < 1)
         break;
      putchar('\n');
      a = get_matrix_space(m, n);
      fill_matrix(a, m, n);
      wrt_matrix("A", a, m, n);
      printf("trace(A) = %.1f\n\n", trace(a, m, n));
      release_matrix_space(a);
   }
   printf("\nBye!\n\n");
   return 0;
}
