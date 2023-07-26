#include <iostream.h>

void swap(int& a, int& b);

int main()
{
   int   a = 3, b = 7;

   cout << "\n";
   cout << "   Before swap: a = " << a << ", b = " << b << "\n";
   swap(a, b);
   cout << "    After swap: a = " << a << ", b = " << b << "\n\n";
}

void swap(int& a, int& b)
{
   int   tmp;

   tmp = a;
   a = b;
   b = tmp;
}
