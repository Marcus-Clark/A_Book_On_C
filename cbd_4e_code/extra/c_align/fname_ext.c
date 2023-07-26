#include "c_align.h"

fname_ext::fname_ext()
{
   char         word[maxword];
   int          cnt;
   int          i;
   int          n;
   istrstream   iss(file_extensions);

   cnt = 0;
   while (iss >> word)
      ++cnt;
   sz = cnt;
   grewind(iss);
   mlen = 0;
   el = new char* [sz];
   for (i = 0; i < sz; ++i) {
      iss >> word;
      assert(iss);
      n = strlen(word);
      el[i] = new char [n + 1];
      strcpy(el[i], word);
      if (mlen < n)
         mlen = n;
   }
}

fname_ext::~fname_ext()
{
   int   i;
   for (i = 0; i < sz; ++i)
      delete [] el[i];
   delete [] el;
}

ostream& operator<<(ostream& os, fname_ext e)
{
   int   i;
   int   sz = e.size();

   for (i = 0; i < sz; ++i) {
      os << e[i];
      os << ((i < sz - 1) ? " " : "");
   }
   return os;
}
