// ---
// Greatest common divisor program.
//

#include  <iostream.h>

int main()
{
   int  m, n, r;

   cout << "\nGCD program in C++:\n";
   cout << "\nEnter two integers: ";
   cin >> m >> n;
   cout << "\nGCD(" << m << ", " << n << ") = " ;
   while (n != 0) {
      r = m % n;
      m = n;
      n = r;
   }
   cout << m << endl << endl;
}
