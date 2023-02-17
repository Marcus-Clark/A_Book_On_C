#include <stdio.h>
#include <unistd.h>                                      /* for fork() */

#define   N   7

int main(void)
{ 
   int     i;
   pid_t   pid;

   for (i = 1; i <= N; ++i) {
      pid = fork();                                      /* new process */
      if (pid == 0)
         printf("%5d: Hello from child\n", i);
      else if (pid > 0)
         printf("%5d: Hello from parent\n", i);
      else
         printf("%5d: ERROR: Fork did not occur\n", i);
   }
   return 0;
}
