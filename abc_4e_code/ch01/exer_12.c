#include <stdio.h>

int main(void)
{
   int   i;

   printf("\n\n:::::  A TABLE OF POWERS  :::::\n\n");
   printf("%7s%10s%13s%13s%13s\n%7s%10s%13s%13s%13s\n",
      "Integer", "Square", "3rd power", "4th power", "5th power",
      "-------", "------", "---------", "---------", "---------");
   for (i = 1; i <= 10; ++i)
      printf("%7d%10d%13d%13d%13d\n", i, i*i, i*i*i, i*i*i*i, i*i*i*i*i);
   printf("\n");
   return 0;
}
