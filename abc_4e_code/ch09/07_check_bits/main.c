#include "check_bits.h"

int main(void)
{
   word   w = {0};
   void   bit_print(int);

   w.bit.b8 = 1;
   w.byte.b0 = 'a';
   printf("w.i = %d\n", w.i);
   bit_print(w.i);
   putchar('\n');
   return 0;
}
