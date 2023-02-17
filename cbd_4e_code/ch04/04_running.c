#include <stdio.h>

void   prn_banner(void);
void   prn_headings(void);
void   read_and_prn_data(void);
int    min(int a, int b);
int    max(int a, int b);

int main(void)
{
   prn_banner();
   prn_headings();
   read_and_prn_data();
   return 0;
}

void prn_banner(void)
{
   printf("\n%s%s%s\n",
      "********************************************\n",
      "*   RUNNING SUMS, MINIMUMS, AND MAXIMUMS   *\n",
      "********************************************\n");
}

void prn_headings(void)
{
   printf("%5s%12s%12s%12s%12s\n\n",
      "Count", "Item", "Sum", "Minimum", "Maximum");
}

void read_and_prn_data(void)
{
   int   cnt = 0, item, sum, smallest, biggest;

   if (scanf("%d", &item) == 1) {
      ++cnt;
      sum = smallest = biggest = item;
      printf("%5d%12d%12d%12d%12d\n",
         cnt, item, sum, smallest, biggest);
      while (scanf("%d", &item) == 1) {
         ++cnt;
         sum += item;
         smallest = min(item, smallest);
         biggest = max(item, biggest);
         printf("%5d%12d%12d%12d%12d\n",
            cnt, item, sum, smallest, biggest);
      }
   }
   else
      printf("No data was input - bye!\n\n");
}
