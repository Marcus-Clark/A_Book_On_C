#include "trace.h"

void chk_cmnd_line(int argc, char **argv)
{
   if (argc > 1 && strcmp(argv[1], "-h") == 0) {
      wrt_info(argv[0]);
      exit(1);
   }
   if (argc > 1) {
      printf("\nERROR: No command line arguments needed.\n\n");
      wrt_info(argv[0]);
      exit(1);
   }
}
