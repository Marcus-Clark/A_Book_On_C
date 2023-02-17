#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void   try_me(int sig);

int main(void)
{
   void   (*value)(int);

   printf("\nTesting signal(): try some interrupts.\n\n");
   /*
   // How the program acts depends on how many calls
   // are made to signal().  Here we do it twice.
   // If you remove one of the lines, you will
   // see a difference.
   */
   value = signal(SIGINT, try_me);
   value = signal(SIGINT, try_me);
   printf("%s%p\n%s%s\n",
      "Returned from signal(): ", value,
      "value == try_me: ", (value == try_me) ? "true" : "false");
   sleep(3);
   printf("\nGoodbye.\n\n");
   return 0;
}

void try_me(int sig)
{
   void   (*value)(int);

   printf("Interrupt received: sig = %d\n", sig);
   value = signal(SIGINT, try_me);
   printf("%s%p\n%s%s\n",
      "Returned from signal(): ", value,
      "value == try_me: ", (value == try_me) ? "true" : "false");
}
