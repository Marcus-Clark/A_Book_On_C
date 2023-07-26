#include "sort.h"

int main(void)
{
   char    a[M];
   float   b[N];
   int     i;

   srand(time(NULL));
   FILL(a, M , "char");
   PRINT(a, M, "%-2c");
   qsort(a, M, sizeof(char), lexico);
   PRINT(a, M, "%-2c");
   printf("---\n");
   FILL(b, N, "float");
   PRINT(b, N, "%-6.1f");
   qsort(b, N, sizeof(float), compare_fractional_part);
   PRINT(b, N, "%-6.1f");
   return 0;
}
