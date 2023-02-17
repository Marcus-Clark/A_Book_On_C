/*
// This program uses popen() to invoke the dir command (MS-DOS),
// but changes all letters written to the screen to lowercase.
*/

#include <ctype.h>
#include <stdio.h>

int main(void)
{
   int    c;
   FILE   *ifp;

   ifp = popen("dir", "r");
   while ((c = getc(ifp)) != EOF)
      putchar(tolower(c));
   pclose(ifp);
   return 0;
}
