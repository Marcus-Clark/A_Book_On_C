#include <stdio.h>

int main(void)
{
   char   c, s[] = "abc", *p = s;
   int    i;
   FILE   *ofp1, *ofp2;

   ofp1 = fopen("tmp1", "w");
   ofp2 = fopen("tmp2", "w");

   for (i = 0; i < 3; ++i) {
      sscanf(s, "%c", &c);
      fprintf(ofp1, "%c", c);
   }
   for (i = 0; i < 3; ++i) {
      sscanf(p++, "%c", &c);
      fprintf(ofp2, "%c", c);
   }
   return 0;
}
