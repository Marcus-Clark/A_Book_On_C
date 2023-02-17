#include <stdio.h>

int main(void)
{
   int   i;

   printf("\n\n:::::  A TABLE OF POWERS  :::::\n\n");
   printf("%7s%9s%10s%10s%10s\n%7s%9s%10s%10s%10s\n",
      "Integer", "Square", "Cube", "Quartic", "Quintic",
      "-------", "------", "----", "-------", "-------");
   for (i = 1; i <= 10; ++i)
      printf("%7d%9d%10d%10d%10d\n", i, i*i, i*i*i, i*i*i*i, i*i*i*i*i);
   printf("\n");
   return 0;
}
