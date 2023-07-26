/* Replicate a file with caps. */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>                                    /* for access() */

int main(int argc, char **argv)
{
   int    c;
   FILE   *fp, *tmp_fp;

   if (argc != 2) {
      fprintf(stderr, "\n%s%s%s\n\n%s\n\n",
       "Usage:  ", argv[0], "  filename",
       "The file will be doubled and some letters capitalized.");
      exit(1);
   }
   /*
   // Use access() to check the read / write status of argv[1].
   */
   if (access(argv[1], R_OK | W_OK) != 0) {
      fprintf(stderr, "Cannot open %s - bye!\n", argv[1]);
      exit(1);
   }
   fp = fopen(argv[1], "r+");
   tmp_fp = tmpfile();
   while ((c = getc(fp)) != EOF)
      putc(toupper(c), tmp_fp);
   rewind(tmp_fp);
   fprintf(fp, "---\n");
   while ((c = getc(tmp_fp)) != EOF)
      putc(c, fp);
   return 0;
}
