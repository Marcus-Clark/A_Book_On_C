/* Count each uppercase letter separately. */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
   int   c, i, letter[26];

   for (i = 0; i < 26; ++i)        /* init array to zero*/
      letter[i] = 0;
   while ((c = getchar()) != EOF)  /* count the letters */
      if (isupper(c))
         ++letter[c - 'A'];
   for (i = 0; i < 26; ++i) {      /* print the results */
      if (i % 6 == 0)
         printf("\n");
      printf("%4c:%3d", 'A' + i, letter[i]);
   }
   printf("\n\n");
   return 0;
}
