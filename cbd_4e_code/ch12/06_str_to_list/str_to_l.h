#include <stdio.h>
#include <stdlib.h>

#define   MAXLINE   300

typedef   char         data;                         /* keep the data simple */
typedef   const char   cchr;

struct elem {                                    /* element of a linked list */
   data          d;
   struct elem   *next;
};

typedef   struct elem   elem;

int    count(elem *hp);
void   find_vowels(elem *hp);
elem   *lookup(data c, elem *hp);
elem   *string_to_list(cchr *s);
