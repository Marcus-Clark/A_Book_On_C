#include <stdio.h>

int   a = 1, b = 2, c = 3;           /* global variables */
int   f(void);                       /* function prototype */

int main(void)
{
   printf("%3d\n", f());             /* 12 is printed */
   printf("%3d%3d%3d\n", a, b, c);   /*  4  2  3 is printed */
   return 0;
}

int f(void)
{
   int   b, c;                       /* b and c are local */
                                     /* global b, c are masked */
   a = b = c = 4;
   return (a + b + c);
}
