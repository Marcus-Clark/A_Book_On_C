/* Compute Fibonacci numbers and print time asynchronously. */

#include <stdio.h>
#include <time.h>
#include <unistd.h>                          /* for fork() and sleep() */

int    fib(int);

int main(void)
{
   int   begin = time(NULL), i;

   if (fork() == 0)                                           /* child */
      for (i = 0; i < 30; ++i)
         printf("fib(%2d) = %d\n", i, fib(i));
   else                                                      /* parent */
      for (i = 0; i < 30; ++i) {
         sleep(2);
         printf("elapsed time = %d\n", time(NULL) - begin);
      }
   return 0;
}

int fib(int n)
{
   if (n <= 1)
      return n;
   else
      return (fib(n - 1) + fib(n - 2));
}
