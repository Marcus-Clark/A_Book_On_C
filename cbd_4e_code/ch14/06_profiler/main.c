#include "cmp_sorts.h"

int main(int argc, char** argv)
{
   int   *a, *b, i, n;

   if (argc == 2 && strcmp(argv[1], "-h") == 0) {
      prn_info(argv[0]);
      exit(1);
   }
   if (argc > 1) {
      printf("\nERROR: This program takes no command line arguments.\n\n");
      prn_info(argv[0]);
      exit(1);
   }
   printf("\n%s\n%s\n\n%s",
      "---",
      "Two identical arrays of integers will be sorted.",
      "Input the array size:  ");
   if (scanf("%d", &n) != 1) {
      printf("\nERROR: The integer n not found - bye!\n\n");
      exit(1);
   }
   if (n < 1) {
      printf("\nERROR: The integer n must be positive - bye!\n\n");
      exit(1);
   }
   a = gcalloc(n, sizeof(int));         /* graceful calloc() */
   b = gcalloc(n, sizeof(int));
   for (i = 0; i < n; ++i)              /* create two identical arrays */
      a[i] = b[i] = rand() % 1000;      /* with entries from 0 to 999 */
   qsort(a, n, sizeof(int), compare);
   slow_sort(b, n);
   chk_arrays(a, b, n);                 /* make sure a = b */
   if (n < 100)
      prn_array(a, n);
   else
      printf("\nDone!\n");
   putchar('\n');
   return 0;
}
