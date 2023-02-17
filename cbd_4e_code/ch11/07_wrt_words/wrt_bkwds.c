#include "wrt_bkwds.h"

void wrt_bkwds_by_word(ifstream& ifs)
{
   char         w[maxword];
   static int   cnt = 0;

   if (ifs >> w)
      wrt_bkwds_by_word(ifs);
   cout << w << " ";
   cnt += strlen(w) + 1;
   if (cnt > max_line_len) {
      cout << "\n";
      cnt = 0;
   }
}
