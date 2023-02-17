#include "list.h"

static void   swap(elem *p, elem *q);
static void   swap_int(int *p, int *q);
static void   swap_name(char *s1, char *s2);

void sort_by_age(elem *hp)
{
   elem   *p;
   elem   *q;

   for (p = hp; p != NULL; p = p -> next)
      for (q = p -> next; q != NULL; q = q -> next)
         if (p -> d.age > q -> d.age)
            swap(p, q);
}

void sort_by_name(elem *hp)
{
   printf("Hello from sort_by_name()\n");
}

/*
// We want to swap the members in the structures
//
//    p -> d       and       q -> d
//
// We do not want to swap the pointers p and q themselves.
//       ---
*/

static void swap(elem *p, elem *q)
{
   swap_name(p -> d.name, q -> d.name);
   swap_int(&(p -> d.age), &(q -> d.age));
   swap_int(&(p -> d.weight), &(q -> d.weight));
}

static void swap_int(int *p, int *q)
{
   int   tmp;

   tmp = *p;
   *p = *q;
   *q = tmp;
}

static void swap_name(char *s1, char *s2)
{
   char   tmp[MAXNAME];

   strcpy(tmp, s1);
   strcpy(s1, s2);
   strcpy(s2, tmp);
}
