#include <iostream.h>

int main()
{
   int   a = 1, b = 2, c = 3;

   cout << "\n"
           "a && b && c           has value " << (a && b && c)           << "\n"
           "a && b || c           has value " << (a && b || c)           << "\n"
           "a || b && c           has value " << (a || b && c)           << "\n"
           "a || ! b && ! ! c + 4 has value " << (a || ! b && ! ! c + 4) << "\n"
           "a += ! b && c == ! 5  has value " << (a += ! b && c == ! 5)  << "\n"
           "\n";
}
