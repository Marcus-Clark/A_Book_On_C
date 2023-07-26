#include <stdio.h>

#define   A_SIZE   10
#define   B_SIZE   20

void   f(int *a, int *b);

int main(void)
{
   int   a[A_SIZE];
   int   b[B_SIZE];

   f(a, b);
}

void f(int *a, int *b)
{
   int   i;

   #if A_SIZE < B_SIZE
      #error "Incompatible sizes"
   #endif

   for (i = 0; i < B_SIZE; ++i)
      a[i] = b[i];
}
