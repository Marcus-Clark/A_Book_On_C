/*
// This program uses popen() to invoke the ls command (UNIX),
// but changes all letters written to the screen to uppercase.
*/

#include <ctype.h>
#include <stdio.h>

int main(void)
{
   int    c;
   FILE   *ifp;

   ifp = popen("ls", "r");
   while ((c = getc(ifp)) != EOF)
      putchar(toupper(c));
   pclose(ifp);
   return 0;
}
