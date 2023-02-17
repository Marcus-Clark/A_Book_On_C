#include <stdio.h>

void   prn_message(void);            /* fct prototype */
int main(void)
{
   prn_message();                    /* fct invocation */
}

void prn_message(void)               /* fct definition */
{
   printf("A message for you:  ");
   printf("Have a nice day!\n");
}
