#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define   M   32                                /* size of a[] */
#define   N   11                                /* size of b[] */
#define   fractional_part(x)   (x - (int) x)
#define   random_char()        (rand() % 26 + 'a')
#define   random_float()       (rand() % 100 / 10.0)

#define   FILL(array, sz, type)     \
   if (strcmp(type, "char") == 0)   \
      for (i = 0; i < sz; ++i)      \
         array[i] = random_char();  \
   else                             \
      for (i = 0; i < sz; ++i)      \
         array[i] = random_float()

#define   PRINT(array, sz, cntrl_string)  \
   for (i = 0; i < sz; ++i)               \
      printf(cntrl_string, array[i]);     \
   putchar('\n')

int   compare_fractional_part(const void *, const void *);
int   lexico(const void *, const void *);
