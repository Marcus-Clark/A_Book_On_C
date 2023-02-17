/* Copy stdin to stdout, except single space only. */

#include <stdio.h>

int main(void)
{
   int   c, last_c = '\0';

   while ((c = getchar()) != EOF) {
      if (c == '\n') {
         if (last_c != '\n')
            putchar('\n');
      }
      else
         putchar(c);
      last_c = c;
   }
   return 0;
}
