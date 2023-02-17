#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define   MAXSTRING   100

int main(void)
{
   char   cmnd[MAXSTRING];
   char   tfn[MAXSTRING];       /* tmp filename */
   int    c;
   FILE   *ifp;

   tmpnam(tfn);
   sprintf(cmnd, "dir > %s", tfn);
   system(cmnd);
   ifp = fopen(tfn, "r");
   while ((c = getc(ifp)) != EOF)
      putchar(tolower(c));
   remove(tfn);
   return 0;
}
