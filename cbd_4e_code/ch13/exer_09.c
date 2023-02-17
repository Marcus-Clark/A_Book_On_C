/*
// ---
// Exercise 9 on page 494:
//
// First compile and execute this program as written.  Then
// experiment enough with the program so that you understand
// its effects.  Finally, you must change this program to
// provide useful information to the user.
//
// When you give the command
//
//    pgm
//
// and nothing happens, then your next logical choice is to
// give the command
//
//    pgm -h
//
// This should cause a short help message to be printed.
// Make sure that the program you write for this
// exercise does all of this.
*/

#include <stdio.h>

#define   MAXLINE   300

int main(void)
{
   char   line[MAXLINE], store[MAXLINE];
   FILE   *ifp = stdin;

   while (fgets(line, MAXLINE, ifp) != NULL) {
      if (sscanf(line, " // %[^\n]", store) == 1) {
         fputs(store, stdout);
         fputs("\n", stdout);     /* restore the newline */
      }
      else
         fputs(line, stdout);
   }
   return 0;
}
