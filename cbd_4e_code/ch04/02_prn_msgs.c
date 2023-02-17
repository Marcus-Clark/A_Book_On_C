#include <stdio.h>

void   prn_message(int k);

int main(void)
{
   int   n;

   printf("%s",
      "There is a message for you.\n"
      "How many times do you want to see it?  ");
   scanf("%d", &n);
   prn_message(n);
   return 0;
}

void prn_message(int k)
{
   int   i;

   printf("Here is the message:\n");
   for (i = 0; i < k; ++i)
      printf("   Have a nice day!\n");
}
