#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define   MAXLINE   100

int main(int argc, char **argv)
{
   char   line[MAXLINE];
   char   *pattern;
   int    cnt;
   FILE   *ifp;

   if (argc != 3) {
      printf("%s%s%s\n",
         "---\n"
         "Usage:  ", argv[0], " ...\n"
         "\n"
         "This program ...\n");
      exit(1);
   }
   if ((ifp = fopen(argv[2], "r")) == NULL) {
      fprintf(stderr, "\nCannot open %s - bye!\n\n", argv[2]);
      exit(1);
   }
   pattern = argv[1];
   /*
   // Search for pattern in each line.  If pattern is
   // found, print the line along with its line number.
   */
   cnt = 0;
   while (fgets(line, MAXLINE, ifp) != NULL) {
      ++cnt;
      if (strstr(line, pattern) != NULL)
         printf("%5d: %s", cnt, line);
   }
   return 0;
}
