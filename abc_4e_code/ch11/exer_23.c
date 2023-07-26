#include <stdio.h>
#include <stdlib.h>

#define   MAXSTRING   100

int main(int argc, char **argv)
{
   char   command[MAXSTRING];

   sprintf(command, "sort -r %s", argv[1]);
   system(command);
   return 0;
}
