#include <stdio.h>

typedef   char *   string;

int main(void)
{
   string   a[] = {"I", "like", "to", "fight,"},
            b[] = {"pinch,", "and", "bight."};

   printf("%s %s %s %s %s %s %s\n",
      a[0], a[1], a[2], a[3], b[0], b[1], b[2]);
   return 0;
}
