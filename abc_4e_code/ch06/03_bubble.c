void bubble(int a[], int n)     /* n is the size of a[] */
{
   int    i, j;
   void   swap(int *, int *);

   for (i = 0; i < n - 1; ++i)
      for (j = n - 1; j > i; --j)
         if (a[j-1] > a[j])
            swap(&a[j-1], &a[j]);
}
