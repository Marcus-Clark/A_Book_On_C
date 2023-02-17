#include <stdio.h>

struct test {
   unsigned   a : 1, b : 2, c : 3;
};

int main(void)
{
   int           i;
   struct test   x;

   for (i = 0; i < 23; ++i) {
      x.a = x.b = x.c = i;
      printf("x.a = %d   x.b = %d   x.c = %d\n",
              x.a, x.b, x.c);
   }
   return 0;
}
