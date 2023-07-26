#include "count.h"

void prn_info(cchr *pgm_name)
{
   printf("\n%s%s%s",
      "Usage:  ", pgm_name, " [-h] filename\n"
      "\n"
      "This program reads words from the named file, counts the words\n"
      "as they are being read in, creates a linked list of elements\n"
      "with each element containing a word, and counts the number\n"
      "of elements in the linked list.\n"
      "\n"
      "The two counts, which must be the same, gets reported.\n"
      "\n");
}
