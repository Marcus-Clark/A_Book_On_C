#include "g_lib.h"

void ggetcwd(char* cwd, size_t maxstring)
{
   if (getcwd(cwd, maxstring) == NULL) {
      fprintf(stderr, "\nERROR: getcwd() failed - bye!\n\n");
      exit(1);
   }
}
