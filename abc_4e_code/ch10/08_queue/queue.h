/* A linked list implementation of a queue. */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define   EMPTY      0
#define   FULL       10000

typedef   unsigned int         data;
typedef   enum {false, true}   boolean;

struct elem {                   /* an element in the queue */
   data          d;
   struct elem   *next;
};

typedef   struct elem   elem;

struct queue {
   int    cnt;                  /* a count of the elements */
   elem   *front;               /* ptr to the front element */
   elem   *rear;                /* ptr to the rear element */
};

typedef   struct queue   queue;

void      initialize(queue *q);
void      enqueue(data d, queue *q);
data      dequeue(queue *q);
data      front(const queue *q);
boolean   empty(const queue *q);
boolean   full(const queue *q);
