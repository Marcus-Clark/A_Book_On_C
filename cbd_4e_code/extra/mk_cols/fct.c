#include "mk_cols.h"

void capitalize(char* word)
{
   char*   p;

   for (p = word; *p != '\0'; ++p)
      if (islower(*p))
         *p = toupper(*p);
}

void mk_adjustments(int* fw, int n)
{
   int   j;
   int   mnbsbc;                    // min # of blank spaces between cols
   int   screen_width;
   int   additional_space;
   int   sum;

   assert(n > 0);
   if (o.space_option())
      mnbsbc = o.get_space();
   else
      mnbsbc = default_mnbsbc;
   if (o.width_option())
      screen_width = o.get_width();
   else
      screen_width = default_screen_width;
   //
   // Set the minumum field widths,
   // but leave the field width
   // of the last column
   // undisturbed.
   //
   for (j = 1; j < n; ++j)
      fw[j] += mnbsbc;
   //
   // If the space option is off, allow
   // for more space between columns.
   //
   if (o.space_option() == off) {
      sum = 0;
      for (j = 1; j <= n; ++j)
         sum += fw[j];
      if (sum < screen_width) {
         additional_space = (screen_width - sum) / n;
         //
         // Leave fw[n] as is.
         //
         for (j = 1; j < n; ++j)
            fw[j] += additional_space;
      }
   }
}

cchr* report(off_on val)
{
   return ((val == off) ? "off" : "on");
}
