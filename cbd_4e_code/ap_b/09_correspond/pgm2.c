#include <ctype.h>
#include <stdio.h>

int main(void)
{
   int   c;
   int   cnt = 0;

   while ((c = (getchar)()) != EOF)
      if ((isalpha)(c))
         ++cnt;
   printf("\n   Number of letters: %d\n\n", cnt);
   return 0;
}
