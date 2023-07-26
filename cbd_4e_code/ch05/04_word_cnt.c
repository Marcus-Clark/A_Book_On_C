#include <ctype.h>
#include <stdio.h>

int found_next_word(void);

int main()
{
   int   word_cnt = 0;

   while (found_next_word() == 1)
      ++word_cnt;
   printf("\nNumber of words = %d\n\n", word_cnt);
   return 0;
}

int found_next_word(void)
{
   int   c;

   while (isspace(c = getchar()))
      ;                /* skip white space */
   if (c != EOF) {     /* found a word */
      while ((c = getchar()) != EOF && !isspace(c))
       ;     /* skip all except EOF and white space */
      return 1;
   }
   return 0;
}
