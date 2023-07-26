#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define   MAXSTRING   100

typedef   const char   cchr;

FILE   *cfopen(cchr *filename, cchr *mode);
FILE   *gfopen(cchr *filename, cchr *mode);
void   get_info(char *filename, int *n_ptr);
void   prn_rand(FILE *ofp, int n);
