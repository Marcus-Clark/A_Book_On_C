#include "dining_philosophers.h"

/* Acquire chopsticks, input is philosopher number. */

void pick_up(int me)
{
   if (me == 0) {
      wait(chopstick[Right(me)]);
      printf("Philosopher %d picks up right chopstick\n", me);
      sleep(1);      /* simulate slow picking up to encourage deadlock */
      wait(chopstick[Left(me)]);
      printf("Philosopher %d picks up left chopstick\n", me);
   }
   else {
      wait(chopstick[Left(me)]);
      printf("Philosopher %d picks up left chopstick\n", me);
      sleep(1);      /* simulate slow picking up to encourage deadlock */
      wait(chopstick[Right(me)]);
      printf("Philosopher %d picks up right chopstick\n", me);
   }
}

/* Relinquish chopsticks, input is the philosopher number. */

void put_down(int me)
{
   signal(chopstick[Left(me)]);
   signal(chopstick[Right(me)]);
}

/* Philosopher process, input is the philosopher number. */

void philosopher(int me)
{
   char   *s;
   int    i = 1;

   for ( ; ; ++i) {                                         /* forever */
      pick_up(me);
      s = i == 1 ? "st" : i == 2 ? "nd" : i == 3 ? "rd" : "th";
      printf("Philosopher %d eating for the %d%s time\n", me, i, s);
      sleep(Busy_Eating);
      put_down(me);
      printf("Philosopher %d thinking\n", me);
      sleep(Busy_Thinking);
   }
}

semaphore make_semaphore(void)
{
   int   *sema;

   sema = calloc(2, sizeof(int));                 /* permanent storage */
   assert(sema != NULL);
   pipe(sema);
   return sema;
}

void wait(semaphore s)
{
   int   junk;

   if (read(s[0], &junk, 1) <= 0) {
      printf("ERROR: wait() failed, check semaphore creation.\n");
      exit(1);
   }
}

void signal(semaphore s)
{
   if (write(s[1], "x", 1) <= 0) {
      printf("ERROR: write() failed, check semaphore creation.\n");
      exit(1);
   }
}

