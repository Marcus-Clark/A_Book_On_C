#include <stdio.h>

int main(void)
{
   char   cntrl_z = 26;   /* decimal value for control-z */
   int    c;
   FILE   *ifp, *ofp;

   ofp = fopen("tmp", "w");
   fprintf(ofp, "%s%c%s\n",
      "A is for apple", cntrl_z, " and alphabet pie.");
   fclose(ofp);
   ifp = fopen("tmp", "r");         /* open as text file */
   while ((c = getc(ifp)) != EOF)   /* print the file */
      putchar(c);
   fclose(ifp);
   printf("\n---\n");               /* serves as marker */
   ifp = fopen("tmp", "rb");        /* open as binary file */
   while ((c = getc(ifp)) != EOF)   /* print the file */
      putchar(c);
   return 0;
}
