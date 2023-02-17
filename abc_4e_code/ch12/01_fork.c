#include <stdio.h>
#include <unistd.h>                                      /* for fork() */

int main(void)
{ 
   int   value;

   value = fork();                                      /* new process */
   printf("In main: value = %d\n", value);
   return 0;
}
