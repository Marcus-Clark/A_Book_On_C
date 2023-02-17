#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef   const char   cchr;
typedef   double       dbl;

void     chk_cmnd_line(int argc, char **argv);
void     fill_matrix(dbl **a, int m, int n);
dbl **   get_matrix_space(int m, int n);
void     release_matrix_space(dbl **a);
dbl      trace(dbl **a, int m, int n);
void     wrt_info(cchr *pgm_name);
void     wrt_matrix(cchr *s, dbl **a, int m, int n);
