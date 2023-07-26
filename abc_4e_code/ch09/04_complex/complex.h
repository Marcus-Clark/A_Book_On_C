#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define   MAXLINE     100
#define   MAXSTRING   100

enum no_yes {no, yes};

typedef   const char    cchr;
typedef   double        dbl;
typedef   enum no_yes   no_yes;

struct complex {
   dbl   re;      /* real part */
   dbl   im;      /* imag part */
};

typedef   struct complex   complex;

void     add(complex *a, complex *b, complex *c);
void     error_exit_not_a_complex_number(cchr *s);
void     error_exit_too_many_numbers(cchr *line);
no_yes   get_complex_number(complex *z, cchr *s);
no_yes   get_from_user(complex *a, complex *b);
void     mult(complex *a, complex *b, complex *c);
cchr *   skip_number(cchr *p);
void     wrt(char *s, complex z);
