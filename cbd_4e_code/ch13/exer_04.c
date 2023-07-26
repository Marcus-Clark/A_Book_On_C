/*
// First, compile this program and put the executable code
// into a file, say pgm.  Then you can give the following
// command:
//
//    pgm < my_file
//
// Once you see what the program does, then you can
// think about how the program does it.
*/

#include <stdio.h>

int main(void)
{
   char   s[300];

   while (scanf("%*[^\n]%*[\n]%[^\n]%*[\n]", s) == 1)
      printf("%s\n", s);
   return 0;
}
