//
// The value of a a variable and the address
// of a variable are conceptually different.
//

#include <iostream.h>

int main()
{
   int   i = 777;
   int*  p = &i;

   cout <<
      "\n"
      "     Value of i: " << *p << "\n"
      "   Address of i: " << (unsigned) p << " or " << p << "\n"
      "\n";
}
