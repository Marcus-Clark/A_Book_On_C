#include "dining_philosophers.h"

int main(void)
{
   int   i;

   for (i = 0; i < N; ++i) {            /* put chopsticks on the table */
      chopstick[i] = make_semaphore();
      signal(chopstick[i]); 
   }
   for (i = 0; i < N - 1; ++i)                  /* create philosophers */
      if (fork() == 0)
         break;
   philosopher(i);                       /* all executing concurrently */
   return 0;
}
