#include "list.h"

int main(void)
{
   int    cnt = 0;
   int    max_age;
   int    max_weight;
   int    n;
   data   *a;
   elem   *hp;
   elem   *p;
   FILE   *ifp;

   get_max_age_weight(&max_age, &max_weight);
   ifp = fopen(INPUT, "r");
   if (ifp == NULL) {
      printf("\nCannot open %s - bye!\n\n", INPUT);
      exit(1);
   }
   create_array(&a, &n, ifp);
   fclose(ifp);
   hp = create_list(a, n);
   prn_heading();
   for (p = hp; p != NULL; p = p -> next) {
      if (p -> d.age <= max_age && p -> d.weight <= max_weight) {
         ++cnt;
         prn_data(&(p -> d));
      }
   }
   printf("\n   Count: %d\n\n", cnt);
   return 0;
}
