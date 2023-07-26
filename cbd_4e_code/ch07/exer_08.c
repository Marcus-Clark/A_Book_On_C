/*
// If the programmer has made a typedef, then that typedef can
// be used in another one.  This program illustrates the idea
// in a very simple way.
*/

#include <stdio.h>

typedef   enum no_yes {no, yes, maybe}   no_yes;
typedef   no_yes                         chk_it_out;

int main(void)
{
   char         c;
   chk_it_out   ans;

   printf("Do you like vegetables?  ");
   scanf(" %c", &c);
   if (c == 'n' || c == 'N')
      ans = no;
   else if (c == 'y' || c == 'Y')
      ans = yes;
   else
      ans = maybe;
   switch (ans) {
   case yes:
      printf("The answer was yes.\n");
   case no:
      printf("The answer was no.\n");
   case maybe:
      printf("You probably typed a nonsense reply.\n");
   default:
      printf("Impossible to get here.\n");
   }
   return 0;
}
