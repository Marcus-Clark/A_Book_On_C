#include <stdio.h>

void   r_prn_message(int k);

int main(void)
{
   int   n;

   printf("\n%s",
      "There is a message for you.\n"
      "How many times do you want to see it?  ");
   scanf("%d", &n);
   printf("\nHere is the message:\n\n");
   r_prn_message(n);
   putchar('\n');
   return 0;
}

void r_prn_message(int k)
{
   if (k > 0) {
      printf("   Have a nice day!\n");
      r_prn_message(k - 1);              /* recursive fct call */
   }
}
