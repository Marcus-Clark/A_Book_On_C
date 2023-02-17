#include <stdio.h>

char   *forever(char *s);

#define   forever(x)   forever(forever(x))
#define   more         " forever more "

int main(void)
{
   forever(more);
   putchar('\n');
   return 0;
}

#undef forever

char *forever(char *s)
{
   printf("%s", s);
   return s;
}
