/* The dining philosopher program. */

#include <assert.h>
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
