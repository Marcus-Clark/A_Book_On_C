#include <iostream.h>
#include <locale.h>

int main()
{
   char*           s;
   struct lconv*   p;

   cout << "\n"
           "   ---\n";
   if ((s = setlocale(LC_ALL, "")) == NULL)
      cout << "   s = NULL\n\n";
   else
      cout << "   s = " << s << "\n\n";

   p = localeconv();

   cout << "   p -> decimal_point     = " << p -> decimal_point << "\n"
           "   p -> thousands_sep     = " << p -> thousands_sep << "\n"
           "   p -> int_curr_symbol   = " << p -> int_curr_symbol << "\n"
           "   p -> currency_symbol   = " << p -> currency_symbol << "\n"
           "   p -> mon_decimal_point = " << p -> mon_decimal_point << "\n"
           "   p -> positive_sign     = " << p -> positive_sign << "\n"
           "   p -> negative_sign     = " << p -> negative_sign << "\n"
           "   p -> frac_digits       = " << p -> frac_digits << "\n"
           "\n";
}
