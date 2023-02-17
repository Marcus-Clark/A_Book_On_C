#include <stdio.h>

void   count_down(int n);

int main(void)
{
   count_down(10);
   return 0;
}

void count_down(int n)
{
   if (n) {
      printf("%d !  ", n);
      count_down(n - 1);
   }
   else
      printf("\nBLAST OFF\n");
}
