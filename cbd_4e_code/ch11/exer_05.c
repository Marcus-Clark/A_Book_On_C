#include <string.h>
#include <stdio.h>

#define   MAXWORD   30    /* max characters in a word */
#define   N         50    /* number of words in array */

int   r_strcmp(char *p, char *q);

int main(void)
{
   int    i, j;
   char   word[N][MAXWORD],   /* an array of N words */
          temp[MAXWORD];

   for (i = 0; i < N; ++i)
      scanf("%s", word[i]);
   for (i = 0; i < N - 1; ++i)
      for (j = i + 1; j < N; ++j)
       if (r_strcmp(word[i], word[j]) > 0) {
          strcpy(temp, word[i]);
          strcpy(word[i], word[j]);
          strcpy(word[j], temp);
       }
   for (i = 0; i < N; ++i)
      printf("%s\n", word[i]);
   return 0;
}

/*
// The body of r_strcmp() needs to be written.
*/

int r_strcmp(char *p, char *q)
{
   static int   cnt = 0;

   if (++cnt >= 7)
      exit(1);
   printf("Hello from r_strcmp().\n");
   return 0;
}
