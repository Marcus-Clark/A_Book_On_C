#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "g_lib.h"

typedef   const char   cchr;

void   chk_arrays(int *a, int *b, int n);
int    compare(const void *vp, const void *vq);
void   prn_array(int *a, int n);
void   prn_info(cchr *pgm_name);
void   slow_sort(int *a, int n);
