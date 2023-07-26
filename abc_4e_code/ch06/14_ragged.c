#include <stdio.h>

int main(void)
{
   char   a[2][15] = {"abc:", "a is for apple"};
   char   *p[2]    = {"abc:", "a is for apple"};

   printf("%c%c%c %s %s\n%c%c%c %s %s\n",
      a[0][0], a[0][1], a[0][2], a[0], a[1],
      p[0][0], p[0][1], p[0][2], p[0], p[1]);
   return 0;
}
