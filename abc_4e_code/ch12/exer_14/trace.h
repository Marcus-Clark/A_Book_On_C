#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define   MAXSTRING   100

typedef   const char   cchr;
typedef   double       dbl;

void      chk_cmnd_line(int argc, char **argv);
void      fill_tensor(dbl ***a, int m, int n, int p);
dbl ***   get_tensor_space(int m, int n, int p);
void      release_tensor_space(dbl ***a);
dbl       trace(dbl ***a, int m, int n, int p);
void      wrt_info(cchr *pgm_name);
void      wrt_matrix(cchr *s, dbl **a, int m, int n);
void      wrt_tensor(cchr *s, dbl ***a, int m, int n, int p);
