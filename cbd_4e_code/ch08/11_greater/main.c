#include "try_me.h"

int main()
{
   char   c1;
   char   c2;
   int    cnt = 0;

   cin.unsetf(ios::skipws);       // unset the skip white space flag
   while (cin >> c1 >> c2) {
      if (isalpha(c1) && isalpha(c2))
         cnt += greater(c1, c2);
      cout << c1 << c2;
   }
   cout << "\n"
           "\n"
           "Interchange count: " << cnt << "\n"
           "\n";
}
