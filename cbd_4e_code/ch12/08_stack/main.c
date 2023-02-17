// ---
// Test the stack implementation by reversing a string.
//

#include "stack.h"

const int   maxdata   = 1000;
const int   maxline   = 300;

const int   empty     = -1;
const int   full      = maxdata - 1;

int main()
{
   char    line[maxline];
   cchr*   p;
   stack   stk;

   cout << "\n"
           "   This program uses stack operations to reverse the\n"
           "   characters in a line entered at the keyboard.\n"
           "\n"
           "     Input a line: ";
   cin.getline(line, maxline);
   for (p = line; *p != '\0'; ++p) {
      if (stk.is_full() == yes) {
         cout << "\n   OVERFLOW: The stack is full - bye!\n\n";
         exit(1);
      }
      stk.push(*p);
   }
   cout << "   From the stack: ";
   while (stk.is_empty() == no)
      cout << stk.pop();
   cout << "\n\n";
}
