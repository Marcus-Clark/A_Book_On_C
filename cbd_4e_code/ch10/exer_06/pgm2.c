/* Character processing: change a line. */

#include <assert.h>
#include <stdio.h>

#define   MAXLINE   10

char   *change(char *s);
void   read_in(char s[]);

int main(void)
{
   char   line[MAXLINE], *change(char *);
   void   read_in(char *);

   printf("\nWhat is your favorite line?  ");
   read_in(line);
   printf("\n%s\n\n%s\n\n",
      "Here it is after being changed:", change(line));
   return 0;
}

void read_in(char s[])
{
   int    c;
   int    cnt = 0;
   int    i = 0;

   while ((c = getchar()) != EOF && c != '\n') {
      ++cnt;
      if (cnt >= MAXLINE) {
         printf("\n%s%d%s",
                "SORRY: Your line has too many characters.\n"
                "       The limit is ", MAXLINE, " characters - bye!\n"
                "\n");
         exit(1);
      }
      s[i++] = c;
   }
   s[i] = '\0';
}

char *change(char *s)
{
   static char   new_string[MAXLINE];
   char          *p = new_string;

   *p++ = '\t';
   for ( ; *s != '\0'; ++s)
      if (*s == 'e')
       *p++ = 'E';
      else if (*s == ' ') {
       *p++ = '\n';
       *p++ = '\t';
      }
      else
       *p++ = *s;
   *p = '\0';
   return new_string;
}
