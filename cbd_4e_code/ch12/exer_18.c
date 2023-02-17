#include <stdio.h>

struct s1 {
   char   c1;
   char   c2;
   int    i;
};

struct s2 {
   char   c1;
   int    i;
   char   c2;
};

int main(void)
{
   printf("\n%s%u\n%s%u\n\n",
      "   sizeof(struct s1) = ", sizeof(struct s1),
      "   sizeof(struct s2) = ", sizeof(struct s2));
   return 0;
}
