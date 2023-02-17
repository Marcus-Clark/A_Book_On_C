#include <stdio.h>

int   a = 1, b = 2, c = 3;              /* external variables */

int   f(void);                               /* fct prototype */

int main(void)
{
   printf("%3d\n", f());             /* 12       gets printed */
   printf("%3d%3d%3d\n", a, b, c);   /*  4  2  3 gets printed */
   return 0;
}
