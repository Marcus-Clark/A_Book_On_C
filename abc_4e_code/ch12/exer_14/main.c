#include "trace.h"

int main(int argc, char **argv)
{
   int   m;                                          /* number of rows */
   int   n;                                       /* number of columns */
   int   p;                                       /* number of columns */
   int   val;
   dbl   ***a;                                               /* tensor */

   srand(time(NULL));              /* seed the random number generator */
   chk_cmnd_line(argc, argv);
   printf("%s\n",
      "---\n"
      "This program creates space for an m x n x p tensor A, fills it\n"
      "with randomly distributed digits from -9 to +9, and then prints\n"
      "the tensor A and its trace.\n");
   for ( ; ; ) {
      printf("Input m, n, and p:  ");
      val = scanf("%d%d%d", &m, &n, &p);
      if (val != 3 || m < 1 || n < 1 || p < 1)
         break;
      putchar('\n');
      a = get_tensor_space(m, n, p);
      fill_tensor(a, m, n, p);
      wrt_tensor("A", a, m, n, p);
      printf("trace(A) = %.1f\n\n", trace(a, m, n, p));
      release_tensor_space(a);
   }
   printf("\nBye!\n\n");
   return 0;
}
