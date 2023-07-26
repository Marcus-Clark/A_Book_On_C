#include "list.h"

int main(void)
{
   int    cnt = 0;
   int    n;
   data   *a;
   elem   *hp;
   elem   *p;
   FILE   *ifp;

   ifp = fopen(INPUT, "r");
   if (ifp == NULL) {
      printf("\nCannot open %s - bye!\n\n", INPUT);
      exit(1);
   }
   create_array(&a, &n, ifp);
   fclose(ifp);
   hp = create_list(a, n);
   sort_by_age(hp);
   prn_heading();
   for (p = hp; p != NULL; p = p -> next) {
      ++cnt;
      prn_data(&(p -> d));
   }
   printf("\n   %s:%3d\n\n", "Count", cnt);
   return 0;
}
