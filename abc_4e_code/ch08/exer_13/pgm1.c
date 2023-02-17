#include <stdio.h>

#define   YANK(x)   s = #x

int main(void)
{
   char   *s;

   YANK("Go home, Yankee!");
   printf("%s\n", s);
   return 0;
}
