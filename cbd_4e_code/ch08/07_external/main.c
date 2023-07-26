/*
// The external variables are declared at the top
// of this file, just before main().  If they are
// not declared here, they must be declared in
// some other .c file, outside of any function
// definition.
*/

#include "try_me.h"

cchr*   msg = "Hello!  This message can be used anywhere.";

int     a = 1;
int     b = 2;
int     c = 3;

int main(void)
{
   putchar('\n');
   print_all();
   increment_all();
   print_all();
   decrement_all();
   print_all();
   return 0;
}
