#include <stdio.h>
#include <ctype.h>

#define   NWORDS   3        /* number of words per line */

int   process(int *, int *, int *);

int main(void)
{
   int   c, nchars = 0, nletters = 0;

   while ((c = getchar()) != EOF)
      if (process(&c, &nchars, &nletters) == 1)
         putchar(c);
      printf("\n%s%5d\n%s%5d\n\n",
             "Number of characters:", nchars,
             "Number of letters:   ", nletters);
   return 0;
}

int process(int *p, int *nchars_ptr, int *nletters_ptr)
{
   static int   cnt = 0, last_char = ' ';

   if (isspace(last_char) && isspace(*p))
      return 0;
   if (isalpha(*p)) {
      ++*nletters_ptr;
      if (islower(*p))
         *p = toupper(*p);
   }
   else if (isspace(*p))
      if (++cnt % NWORDS == 0)
         *p = '\n';
      else
       *p = ' ';
   ++*nchars_ptr;
   last_char = *p;
   return 1;
}
