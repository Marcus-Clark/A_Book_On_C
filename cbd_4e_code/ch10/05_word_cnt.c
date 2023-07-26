/*
// Count the number of words in a file.
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

const int   maxstring   = 100;

int main()
{
   char   ifn[maxstring];      /* infile name */
   char   word[maxstring];
   int    cnt = 0;
   FILE   *ifp;

   printf("\n   Input the name of a file: ");
   assert(scanf("%s", ifn) == 1);
   if ((ifp = fopen(ifn, "r")) == NULL) {
      printf("\n   Cannont open %s - bye!\n\n", ifn);
      exit(1);
   }
   while (fscanf(ifp, "%s", word) == 1)
      ++cnt;
   printf("\n   Word count: %d\n\n", cnt);
   return 0;
}
