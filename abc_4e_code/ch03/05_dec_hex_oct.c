/* Decimal, hexadecimal, octal conversions. */

#include <stdio.h>

int main(void)
{
   printf("%d  %x  %o\n", 19, 19, 19);        /* 19  13  23 */
   printf("%d  %x  %o\n", 0x1c, 0x1c, 0x1c);  /* 28  1c  34 */
   printf("%d  %x  %o\n", 017, 017, 017);     /* 15   f  17 */
   printf("%d\n", 11 + 0x11 + 011);           /* 37         */
   printf("%x\n", 2097151);                   /* 1fffff     */
   printf("%d\n", 0x1FfFFf);                  /* 2097151    */
   return 0;
}
