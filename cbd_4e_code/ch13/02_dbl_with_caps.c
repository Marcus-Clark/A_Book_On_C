#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

FILE   *gfopen(char *fn, char *mode);

int main(int argc, char **argv)
{
   int    c;
   FILE   *fp, *tmp_fp;

   if (argc != 2) {
      fprintf(stderr, "\n%s%s%s\n\n%s%s\n\n",
       "Usage:  ", argv[0], "  filename",
       "The file will be doubled and some ",
       "letters capitalized.");
      exit(1);
   }
   fp = gfopen(argv[1], "r+");       /* open for read write */
   tmp_fp = tmpfile();               /* open for write read */
   while ((c = getc(fp)) != EOF)
      putc(toupper(c), tmp_fp);     /* capitalize lowercase */
   fprintf(fp, "---\n");          /* print marker at bottom */
   rewind(tmp_fp);                    /* mv file pos to top */
   while ((c = getc(tmp_fp)) != EOF)       /* copy tmp file */
      putc(c, fp);                             /* at bottom */
   return 0;
}

/* A graceful version of fopen(). */

FILE *gfopen(char *fn, char *mode)
{
   FILE   *fp;

   if ((fp = fopen(fn, mode)) == NULL) {
      fprintf(stderr, "Cannot open %s - bye!\n", fn);
      exit(1);
   }
   return fp;
}
