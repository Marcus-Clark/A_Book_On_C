#include "wrt_rand.h"

void get_info(char *fname, int *n_ptr)
{
   printf("%s\n\n%s",
      "---\n"
      "This program creates a file of random numbers.",
      "How many random numbers would you like?  ");
   scanf("%d", n_ptr);
   printf("\nIn what file would you like them?  ");
   assert(scanf("%s", fname) == 1);
}
