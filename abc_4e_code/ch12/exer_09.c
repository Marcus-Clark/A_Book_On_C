#include <stdio.h>
#include <signal.h>
#include <math.h>                          /* HUGE_VAL is defined here */

int main(void)
{
   double   x = HUGE_VAL, y = HUGE_VAL;

   signal(SIGFPE, SIG_IGN);                            /* ignore SIGFE */
   printf("Ignore signal: x * y = %e\n", x * y);
   signal(SIGFPE, SIG_DFL);                                 /* default */
   printf("Default signal: x * y = %e\n", x * y);
   return 0;
}
