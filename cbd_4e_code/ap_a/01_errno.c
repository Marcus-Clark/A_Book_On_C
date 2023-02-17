/*
// In this program we are trying to open for reading
// the file xxx, which does not exist.
*/

#include <errno.h>
#include <stdio.h>

extern int    sys_nerr;
extern char   *sys_errlist[];

int main(void)
{
   FILE   *ofp;

   ofp = fopen("xxx", "r");
   if (errno > 0 && errno < sys_nerr) {
      perror("TROUBLE");
      fprintf(stderr, "TROUBLE: %s\n", sys_errlist[errno]);
      exit(1);
   }
   return 0;
}
