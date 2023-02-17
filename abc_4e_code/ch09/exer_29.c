/*
// The mystery program.
*/

#include <stdio.h>

#if (VAX || PC)
   #define   HEX0   0x6c6c6548
   #define   HEX1   0x77202c6f
   #define   HEX2   0x646c726f
   #define   HEX3   0x00000a21
#else
   #define   HEX0   0x48656c6c
   #define   HEX1   0x6f2c2077
   #define   HEX2   0x6f726c64
   #define   HEX3   0x210a0000
#endif

typedef union {
   char   what[16];
   long   cipher[4];
} mystery;

int main(void)
{
   mystery   x;

   x.cipher[0] = HEX0;     /* put a hex on the mystery */
   x.cipher[1] = HEX1;
   x.cipher[2] = HEX2;
   x.cipher[3] = HEX3;
   printf("%s", x.what);
   return 0;
}
