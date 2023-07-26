#include "g_lib.h"

char *ggetenv(const char *name)
{
   char   *p;

   if ((p = getenv(name)) == NULL) {
      fprintf(stderr, "\n%s%s%s\n\n",
         "SORRY: Environment variable ", name, " not set - bye!");
      exit(1);
   }
   return p;
}
