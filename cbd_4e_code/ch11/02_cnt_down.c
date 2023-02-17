#include <iostream.h>
#include <iomanip.h>

void   count_down(int n);
void   prn_down(int n);

int main(void)
{
   count_down(10);
}

void count_down(int n)
{
   if (n >= 0) {
      prn_down(n);
      count_down(n - 1);
   }
   else
      cout <<"\n    BLAST OFF\n\n";
}

void prn_down(int n)
{
   int   k = n;

   if (n == 10)
      cout << "\n";
   cout << setw(5) << n << " ";
   while (k-- >= 0)
      cout << "!";
   cout << "\n";
}
