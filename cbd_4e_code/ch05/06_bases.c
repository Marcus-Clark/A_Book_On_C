//
// Using different bases in integer I/O.
// Note the use of dec, oct, and hex.
//

#include  <iostream.h>

int main()
{
   int  i = 10, j = 16, k = 24;

   cout << i << '\t' << j << '\t' << k << endl;
   cout << oct << i << '\t' << j << '\t' << k << endl;
   cout << hex << i << '\t' << j << '\t' << k << endl;
   cout << "Enter 3 integers, e.g. 11 11 12a" << endl;
   cin >> i >> hex >> j >> k;
   cout << dec << i << '\t' << j << '\t' << k << endl;
}
