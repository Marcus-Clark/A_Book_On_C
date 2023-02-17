//
// Camelot lasted 1000 days.
//

#include <iostream.h>
#include <string.h>
#include <time.h>

int main(void)
{
   char     s1[100];
   char     s2[100];
   time_t   now;
   time_t   future;

   now      = time(NULL);                      // calendar time
   future   = now + 1000 * 24 * 60 * 60;       // calendar time

   cout << "\n"
           "      Now: " << now    << "\n"
           "   Future: " << future << "\n"
           "\n";

   strftime(s1, 100, "%A   %X %Z   %d %b %y", localtime(&now));
   strftime(s2, 100, "%A   %X %Z   %d %b %y", localtime(&future));

   cout << "      Now: " << s1 << "\n"
           "   Future: " << s2 << "\n"
           "\n";
}
