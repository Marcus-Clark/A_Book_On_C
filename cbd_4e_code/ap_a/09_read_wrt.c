#include <stdio.h>

#define   MAXSTRING   100

int main(void)
{
   char   filename[MAXSTRING];
   int    c;
   FILE   *fp;

   printf("Input a temp file name (it will be overwritten):  ");
   scanf("%s", filename);
   fp = fopen(filename, "r+");
   while ((c = getc(fp)) != EOF)
      putchar(c);
   printf("---\n");
   fflush(fp);   /* needed on the sun, not needed in turbo c */
   fprintf(fp, "Hello from the read/write test program.\n");
   fprintf(fp, "---\n");
   rewind(fp);
   while ((c = getc(fp)) != EOF)
      putchar(c);
   return 0;
}
