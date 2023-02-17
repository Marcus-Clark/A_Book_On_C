#include "shift.h"

const int   maxline = 300;

int main()
{
   char   c1, c2, c3, c4, c5;
   char   line[maxline];
   int    i;
   int    k;
   int    n;

   while (cin.getline(line, maxline)) {
      istrstream   iss(line);          // declaration of iss
      n = strlen(line);
      k = n / 5;
      iss.unsetf(ios::skipws);         // do not skip white space
      for (i = 0; i < k; ++i) {
         iss >> c1 >> c2 >> c3 >> c4 >> c5;
         shift(c1, c2, c3, c4, c5);
         cout << c1 << c2 << c3 << c4 << c5;
      }
      //
      // Write out the rest of the line.
      // Note the use of pointer arithmetic; see Chapter 9.
      //
      cout << line + 5 * k << "\n";
   }
}
