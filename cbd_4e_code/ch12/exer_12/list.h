#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define   INPUT       "input"
#define   MAXLINE     300
#define   MAXNAME     20
#define   MAXSTRING   100

typedef   const char   cchr;

enum no_yes {no, yes};

typedef   enum no_yes   no_yes;

struct data {                                                        /* data */
   char   name[MAXNAME];
   int    age;
   int    weight;
};

typedef   struct data   data;

struct elem {                                    /* element in a linked list */
   data          d;                            /* each element contains data */
   struct elem   *next;
};

typedef   struct elem   elem;

void     create_array(data **a_ptr, int *n_ptr, FILE *ifp);
elem     *create_list(data a[], int n);
no_yes   is_blank(cchr *line);
no_yes   is_comment(cchr *line);
void     prn_data(data *p);
void     prn_heading(void);
void     sort_by_age(elem *hp);
void     sort_by_name(elem *hp);
