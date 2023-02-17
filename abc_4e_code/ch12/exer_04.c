#include <stdio.h>
#include <unistd.h>                                      /* for execl() */

int main(void)
{ 
   printf("Hello from main()\n");
   if (fork() == 0)
      execl("/usr/bin/date", "date", 0);
   printf("Goodbye!\n");
   return 0;
}
