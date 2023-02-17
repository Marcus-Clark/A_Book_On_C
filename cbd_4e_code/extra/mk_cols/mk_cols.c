#include "mk_cols.h"

void mk_cols(istream* isp)
{
   char         word[maxword];
   char*        q;
   char**       w;                                   // an array of words
   int          cnt;
   int          i;
   int          len;
   int          n;
   int          ncols;
   int          nrows;
   matrix       a;                                   // a matrix of words
 
   istream&     is        = *isp;             // cannot assign an istream
   ostrstream   oss;

   assert(is);
   ncols = o.get_ncols();
   assert(ncols > 0);
   cnt = 0;
   //
   // WHOOPS:
   //    When trying to do the following
   //
   //       echo $MANPATH | mk_cols 1
   //
   //    one gets a single very long word
   //    that overflows the size of word[].
   //    CC and g++ do not protect against
   //    this.  I will increase maxword,
   //    but this does not provide real
   //    protection.
   //
   while (is >> word) {
      ++cnt;
      if (o.uppercase_option())
         capitalize(word);
      oss << word << "\n";
   }
   oss << ends;
   q = oss.str();
   istrstream   iss(q);
   n = cnt;
   w = (new char* [n]) - 1;                     // index from 1, not 0
   for (i = 1; i <= n; ++i) {
      iss >> word;
      assert(iss);
      len = strlen(word);
      w[i] = new char [len + 1];
      strcpy(w[i], word);
   }
   delete [] q;
   if (o.alphabetize_option()) {
      //
      // In qsort(), w[] must be indexed from 0.
      //
      qsort(w + 1, n, sizeof(char*), compare);
   }
   nrows = n / ncols + (n % ncols > 0);
   a.get_space(nrows, ncols);
   //
   // The last row of a[][] can contain NULL pointers;
   // see the function definition for fill() for details.
   //
   a.fill(w, n);
   cout << a;
}
