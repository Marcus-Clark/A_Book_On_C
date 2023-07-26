#ifndef   G_LIB_H
#define   G_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

void *   gcalloc(size_t, size_t);
int      gchmod(const char *, mode_t);
void     ggetcwd(char *, size_t);
void     gfclose(FILE *);
FILE *   gfopen(const char *, const char *);
void     gfseek(FILE *, long, int);
char *   ggetenv(const char *);
void *   gmalloc(size_t);
void     gpclose(FILE *);
FILE *   gpopen(const char *, const char *);
void *   grealloc(void *, size_t);
void     gremove(const char *fname);
void     grename(const char *, const char *);
void     gstat(const char *, struct stat *);
void     gutimes(char *, struct timeval *);

#endif
