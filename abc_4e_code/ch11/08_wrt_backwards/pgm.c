/* Write a file backwards. */

#include <stdio.h>

#define   MAXSTRING   100

int main(void)
{
   char   fname[MAXSTRING];
   int    c;
   FILE   *ifp;

   fprintf(stderr, "\nInput a filename:  ");
   scanf("%s", fname);
   ifp = fopen(fname, "rb");      /* binary mode for MS_DOS */
   fseek(ifp, 0, SEEK_END);       /* move to end of the file */
   fseek(ifp, -1, SEEK_CUR);      /* back up one character */
   while (ftell(ifp) > 0) {
      c = getc(ifp);              /* move ahead one character */
      putchar(c);
      fseek(ifp, -2, SEEK_CUR);   /* back up two characters */
   }
   /*
   // Getting the very first character in the file
   // to print may be delicate.  For some operating
   // systems, this program may work better.
   */
   fseek(ifp, 0, SEEK_SET);       /* move to the beginning of the file */
   c = getc(ifp);
   putchar(c);                    /* print the very first character */
   printf("\n\n");
   return 0;
}
