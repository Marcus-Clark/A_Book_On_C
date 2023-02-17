#include <stdio.h>
#include <unistd.h>

int main(void)
{ 
   int   val;

   val = fork();                           /* new process */
   printf("In main: val = %d\n", val);
   return 0;
}
