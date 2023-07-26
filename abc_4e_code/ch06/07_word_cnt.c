/* Count the number of words in a string. */

#include <ctype.h>

int word_cnt(char *s)
{
   int    cnt = 0;

   while (*s != '\0') {
      while (isspace(*s))     /* skip white space */
         ++s;
      if (*s != '\0') {           /* found a word */
         ++cnt;
         while (!isspace(*s) && *s != '\0')
            ++s;                 /* skip the word */
      }
   }
   return cnt;
}
