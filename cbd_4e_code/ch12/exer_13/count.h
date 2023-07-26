#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define   MAXLINE     700
#define   MAXWORD     100

typedef   const char   cchr;

struct elem {                                    /* element in a linked list */
   char          *word;                            /* each element contains a word */
   struct elem   *next;
};

typedef   struct elem   elem;

int    count(elem *hp);
void   prn_info(cchr *pgm_name);
