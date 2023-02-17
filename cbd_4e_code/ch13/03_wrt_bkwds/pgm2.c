#include <stdio.h>

#define   MAXSTRING   100

int main(void)
{
   char   filename[MAXSTRING];
   int    c;
   FILE   *ifp;

   fprintf(stderr, "\nInput a filename:  ");
   scanf("%s", filename);
   ifp = fopen(filename, "rb");     /* ms-dos binary mode */
   fseek(ifp, 0, 2);                /* move to end of file */
   fseek(ifp, -1, 1);               /* back one character */
   while (ftell(ifp) > 0) {
      c = getc(ifp);                /* ahead one character */
      putchar(c);
      fseek(ifp, -2, 1);            /* back two characters */
   }
   /*
   // The only character that has not been printed
   // is the very first character in the file.
   */
   fseek(ifp, 0, 0);                /* move to the beginning */
   c = getc(ifp);
   putchar(c);
   return 0;
}
