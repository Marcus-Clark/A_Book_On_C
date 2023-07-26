#include <ctype.h>
#include <stdio.h>

#define   N   33

void   repeat(char c, int n);

int main(void)
{
   char   c = 'X';
   int    i;

   for (i = 1; i < N; i += 2) {
      repeat(c, i);
      putchar('\n');
   }
   return 0;
}

void repeat(char c, int n)
{
   int   i;

   for (i = 0; i < n; ++i)
      putchar(c);
}
