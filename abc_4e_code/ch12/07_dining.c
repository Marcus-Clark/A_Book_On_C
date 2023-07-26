/* The dining philosopher program. */

#include <stdio.h>
#include <stdlib.h>                         /* for calloc() and exit() */

#define   N                5                 /* number of philosophers */
#define   Busy_Eating      1 
#define   Busy_Thinking    1
#define   Left(p)          (p)                     /* chopstick macros */
#define   Right(p)         (((p) + 1) % N)

typedef   int *   semaphore;

semaphore   chopstick[N];                              /* global array */

int         fork(void);
semaphore   make_semaphore(void);
void        philosopher(int me);
void        pick_up(int me);
int         pipe(int pd[2]);
void        put_down(int me);
int         read(int fd, void *buf, unsigned len);
void        signal(semaphore s);
void        sleep(unsigned seconds);
void        wait(semaphore s);
int         write(int fd, void *buf, unsigned len);

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

