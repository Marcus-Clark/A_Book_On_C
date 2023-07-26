double sum_square(double f(double), int m, int n)
{
   int      k;
   double   sum = 0.0;

   for (k = m; k <= n; ++k)
      sum += f(k) * f(k);
   return sum;
}
