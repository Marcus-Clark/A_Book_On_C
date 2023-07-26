int sum(int a[][9][2])
{
   int   i, j, k, sum = 0;

   for (i = 0; i < 7; ++i)
      for (j = 0; j < 9; ++j)
         for (k = 0; k < 2; ++k)
            sum += a[i][j][k];
   return sum;
}
