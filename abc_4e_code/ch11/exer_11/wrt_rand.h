#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>          /* for access() */

#define   MAXSTRING   100

FILE   *cfopen(char *fname, char *mode);                   /* careful fopen() */
FILE   *gfopen(const char *filename, const char *mode);   /* graceful fopen() */
void   get_info(char *fname, int *n_ptr);
void   wrt_rand(FILE *ofp, int n);
