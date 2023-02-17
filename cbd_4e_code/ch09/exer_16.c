//
// Exercise 16 on page 359.
//

#include <assert.h>
#include <iostream.h>
#include <string.h>

const int   maxline = 300;

void   strrev(char*& rev_copy, char* line);

int main()
{
   char   line[maxline];
   char*  rev_copy;

   cout << "\nInput a line of words: ";
   cin.getline(line, maxline);
   strrev(rev_copy, line);
   cout << " Here it is backwards: " << rev_copy << "\n\n";
}

void strrev(char*& rev_copy, char* line)   // rev_copy = reverse copy of line
{
   char*   p;
   char*   q;
   int     n;

   n = strlen(line);
   assert(n > 0);
   rev_copy = new char [n + 1];    // allocate new space for rev_copy
   p = rev_copy;                   // p points at the beginning of rev_copy
   q = line + n - 1;               // q points at the last char in line
   while (q >= line)
      *p++ = *q--;                 // do dereferencing and assigning first
   *p = '\0';                      // assign the end of string sentinel
}
