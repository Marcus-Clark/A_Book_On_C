#include "pgm.h"

void fct1(int n)
{
   int   i;

   printf("Hello from fct1()\n");
   for (i = 0; i < n; ++i)
      fct2();
}

void fct2(void)
{
   printf("Hello from fct2()\n");
}
