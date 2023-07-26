#include "careful.h"

void get_info(char *filename, int *n_ptr)
{
   printf("\n%s\n\n%s",
      "This program creates a file of random numbers.",
      "How many random numbers would you like?  ");
   scanf("%d", n_ptr);
   printf("\nIn what file would you like them?  ");
   scanf("%s", filename);
}
