#include "lu_decomp.h"

matrix::matrix()
{
   row_sz  = 0;
   col_sz  = 0;
   base    = NULL;
   el      = NULL;
}

matrix::matrix(int m, int n)
{
   get_space(m, n);
}

void matrix::fill()
{
   int   i;
   int   j;

   //
   // Seed the random number generator.
   //
   srand48(time(NULL));
   for (i = 1; i <= row_sz; ++i)
      for (j = 1; j <= col_sz; ++j)
         el[i][j] = lrand48() % 19 - 9;
}

void matrix::fill(cchr* fname)
{
   char         line[MAXLINE];
   cchr*        p;
   char*        q;
   int          i;
   int          j;
   ifstream     ifs;
   ostrstream   oss;

   srand48(time(NULL));                     // seed the random number generator
   ifs.open(fname);
   if (!ifs)
      error_exit_cannot_open(fname);
   while (ifs.getline(line, MAXLINE)) {
      //
      // Skip blank lines and comment lines.
      //
      for (p = line; isspace(*p); ++p)
         ;
      if (*p == '\0' || strncmp(p, "//", 2) == 0)
         continue;
      oss << line << "\n";
   }
   ifs.close();
   oss << ends;
   istrstream   iss(q = oss.str());
   for (i = 1; i <= row_sz; ++i) {
      for (j = 1; j <= col_sz; ++j) {
         iss >> el[i][j];
         if (!iss)
            error_exit_el_not_found(i, j, fname);
      }
   }
   delete [] q;
}

void matrix::get_space(int m, int n)
{
   int   i;

   assert(m > 0);
   assert(n > 0);
   row_sz = m;
   col_sz = n;
   base = new dbl [m * n];
   el = (new dbl* [m]) - 1;                              // index from 1, not 0
   for (i = 1; i <= m; ++i)
      el[i] = (base + (i - 1) * n) - 1;                  // index from 1, not 0
}

void matrix::identity()
{
   int   i;
   int   j;

   assert(row_sz > 0);
   assert(col_sz > 0);
   for (i = 1; i <= row_sz; ++i)
      for (j = 1; j <= col_sz; ++j)
         el[i][j] = (i == j) ? 1.0 : 0.0;
}

dbl matrix::norm()
{
   int   i;
   int   j;
   dbl   sum = 0.0;

   assert(row_sz > 0);
   assert(col_sz > 0);
   for (i = 1; i <= row_sz; ++i)
      for (j = 1; j <= col_sz; ++j)
         sum += el[i][j] * el[i][j];
   return sqrt(sum);
}

void matrix::release_space()
{
   assert(base != NULL);
   assert(el != NULL);
   delete [] base;
   base = NULL;
   delete [] (el + 1);
   el = NULL;
   row_sz = 0;
   col_sz = 0;
}

matrix& matrix::operator=(matrix a)
{
   int   i;
   int   j;
   int   m = row_sz;
   int   n = col_sz;

   assert(m > 0);
   assert(n > 0);
   assert(a.row_size() == m);
   assert(a.col_size() == n);
   for (i = 1; i <= m; ++i)
      for (j = 1; j <= n; ++j)
         el[i][j] = a[i][j];
   return a;
}
