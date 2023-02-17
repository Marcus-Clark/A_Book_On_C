/*
// If we use pointers instead, the compiler is happy.
*/

#include <stdio.h>

int main(void)
{
   struct husband {
      int           age;
      char          name[10];
      struct wife   *spouse;
   } a;

   struct wife {
      int              age;
      char             name[10];
      struct husband   *spouse;
   } b;

   return 0;
}
