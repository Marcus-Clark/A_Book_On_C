#include <stdio.h>

int   a = 1, b = 2, c = 3;     /* external variables */
int   f(void);

int main(void)
{
   printf("%3d\n", f());
   printf("%3d%3d%3d\n", a, b, c);
   return 0;
}
