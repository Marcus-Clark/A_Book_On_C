#include <stdio.h>

int main(void)
{
   char   c   = 'A';
   char   s[] = "Blue moon!";

   printf("[%c]\n[%2c]\n[%-3c]\n[%s]\n[%3s]\n[%.6s]\n[%-11.8s]\n",
      c, c, c, s, s, s, s);
   return 0;
}
