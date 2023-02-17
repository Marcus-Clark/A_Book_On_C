#include <stdio.h>

int main(void)
{
   char     tfn[100];     /* tfn = tmp filename */

   tmpnam(tfn);
   printf("1: tfn = %s\n", tfn);
   tmpnam(tfn);
   printf("2: tfn = %s\n", tfn);
   tmpnam(tfn);
   printf("3: tfn = %s\n", tfn);
   return 0;
}
