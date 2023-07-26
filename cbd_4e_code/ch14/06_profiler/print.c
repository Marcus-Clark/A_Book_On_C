#include "cmp_sorts.h"

void prn_array(int *a, int n)
{
   int   i;

   for (i = 0; i < n; ++i) {
      if (i % 12 == 0)
         putchar('\n');
      printf("%5d", a[i]);
   }
   putchar('\n');
}

void prn_info(cchr *pgm_name)
{
   printf("%s%s%s",
      "\n"
      "---\n"
      "Usage:  ", pgm_name, "  [-h]\n"
      "\n"
      "This program prompts the user for an array size n.  Then two\n"
      "arrays a[] and b[] of size n are created dynamically, and they\n"
      "are both filled via calls to rand() with identical elements.\n"
      "\n"
      "The array a[] gets sorted with qsort().\n"
      "\n"
      "The array b[] gets sorted with an elementary transposition sort.\n"
      "\n"
      "A internal check confirms that the two arrays have the same elements\n"
      "after they have been sorted.\n"
      "\n"
      "If the array size is less than 100, the elements of a[] get printed.\n"
      "However, we are not interested in the results of the two sorts.\n"
      "                ---\n"
      "\n"
      "---\n"
      "The purpose of this program is to see how the profiler prof works.\n"
      "This program must be compiled with the -p option.  If it is, and\n"
      "the executable code is named \"compare_sorts,\" then you should\n"
      "try the following commands:\n"
      "\n"
      "   compare_sorts        // input 10 when prompted to see an array\n"
      "\n"
      "   compare_sorts        // input 1000 when prompted\n"
      "\n"
      "   prof compare_sorts   // this produces interesting output\n"
      "\n");
}
