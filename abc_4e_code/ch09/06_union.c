#include <stdio.h>

typedef union int_or_float {
   int     i;
   float   f;
} number;

int main(void)
{
   number   n;

   n.i = 4444;
   printf("i: %10d     f: %16.10e\n", n.i, n.f);
   n.f = 4444.0;
   printf("i: %10d     f: %16.10e\n", n.i, n.f);
   return 0;
}
