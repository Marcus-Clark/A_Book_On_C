#include "mk_cols.h"

matrix::matrix()
{
   row_sz = 0;
   col_sz = 0;
   base = NULL;
   el = NULL;
}

// ---
// An array of words w[] is being passed in.
// The space for the matrix has already
// been created.
//

void matrix::fill(char** w, int sz)
{
   int   cnt;
   int   i;
   int   j;
   int   k;
   int   null_ptr_cnt;

   int   m = row_sz;
   int   n = col_sz;

   assert(m > 0);
   assert(n > 0);
   assert(sz > 0);
   assert(sz <= m * n);
   assert(sz > (m - 1) * n);
   null_ptr_cnt = m * n - sz;
   //
   // If m * n is bigger than sz, put some of the
   // pointers in the last row equal to NULL.
   //
   cnt = 0;
   for (j = n - null_ptr_cnt + 1; j <= n; ++j) {
      ++cnt;
      el[m][j] = NULL;
   }
   assert(cnt == null_ptr_cnt);
   //
   // Now load up the matrix with the words.
   //
   if (o.alphabetize_option()) {
      k = 1;
      for (j = 1; j <= n; ++j) {
         for (i = 1; i <= m; ++i) {
            if (i < m || (i == m && j <= n - null_ptr_cnt))
               el[i][j] = w[k++];
         }
      }
   }
   else {
      k = 1;
      for (i = 1; i <= m; ++i) {
         for (j = 1; j <= n; ++j) {
            if (i < m || (i == m && j <= n - null_ptr_cnt))
               el[i][j] = w[k++];
         }
      }
   }
}

void matrix::get_space(int m, int n)
{
   int   i;

   assert(m > 0);
   assert(n > 0);
   row_sz = m;
   col_sz = n;
   base = new cchr* [m * n];
   el = (new cchr** [m]) - 1;                      // index from 1, not 0
   for (i = 1; i <= m; ++i)
      el[i] = (base + (i - 1) * n) - 1;            // index from 1, not 0
}

void matrix::release_space()
{
   assert(base != NULL);
   assert(el != NULL);
   delete [] base;
   delete [] (el + 1);                           // indexed from 1, not 0
}
