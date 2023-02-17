#include <ctype.h>
#include <stdio.h>

#define   MAXWORD   100

void   prn_it_by_word(void);
void   get_word(char *s);

int main(void)
{
   printf("\nInput a line:  ");
   prn_it_by_word();
   printf("\n\n");
   return 0;
}

void prn_it_by_word(void)
{
   char   w[MAXWORD];

   get_word(w);
   if (w[0] != '\n')
      prn_it_by_word();
   printf("%s ", w);
}

void get_word(char *s)
{
   static char   c = '\0';

   if (c == '\n')
      *s++ = c;
   else
      while (!isspace(c = getchar()))
       *s++ = c;
   *s = '\0';
}
