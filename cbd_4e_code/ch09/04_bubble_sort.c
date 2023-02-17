#include <stdio.h>

void   bubble(int a[], int n);
void   prn_array(char* s, int a[], int n);
void   swap(int *p, int *q);

int main(void)
{
   int   a[] = {7, 3, 66, 3, -5, 22, -77, 2};
   int   n;

   n = sizeof(a) / sizeof(int);
   prn_array("Before", a, n);
   bubble(a, n);                /* bubble sort */
   prn_array(" After", a, n);
   putchar('\n');
   return 0;
}

void bubble(int a[], int n)     /* n is the size of a[] */
{
   int   i, j;

   for (i = 0; i < n - 1; ++i)
      for (j = n - 1; i < j; --j)
       if (a[j-1] > a[j])
          swap(&a[j-1], &a[j]);
}

void prn_array(char* s, int a[], int n)
{
   int   i;

   printf("\n%s%s%s", "   ", s, " sorting:");
   for (i = 0; i < n; ++i)
      printf("%5d", a[i]);
   putchar('\n');
}

void swap(int *p, int *q)
{
   int   tmp;

   tmp = *p;
   *p = *q;
   *q = tmp;
}
