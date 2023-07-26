//
// Write a line backwards.
//

#include <iostream.h>

void   wrt_bkwds(void);

int main()
{
   cout << "\nInput a line: ";
   wrt_bkwds();
   cout << "\n\n";
}

void wrt_bkwds(void)
{
   char   c;

   cin.unsetf(ios::skipws);
   if (cin >> c && c != '\n')
      wrt_bkwds();
   cout << c;
}
