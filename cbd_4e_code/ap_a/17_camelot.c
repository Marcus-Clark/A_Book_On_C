//
// Camelot lasted 1000 days.
//

#include <iostream.h>
#include <string.h>
#include <time.h>

void   prn_struct_tm(struct tm *tp);

int main(void)
{
   char         s1[100];
   char         s2[100];
   time_t       future;

   time_t       now      = time(NULL);            // calendar time
   struct tm*   tm_ptr   = localtime(&now);       // ptr to broked down time

   //
   // Capture the current time in s1.
   //
   strftime(s1, 100, "%A   %H:%M:%S %Z   %d %B %Y", tm_ptr);
   //
   // Add 1000 days.
   //
   tm_ptr -> tm_mday += 1000;
   //
   // Convert the broken down time to calendar time.
   //
   future = mktime(tm_ptr);
   //
   // Capture the time 1000 days from now in s2.
   //
   strftime(s2, 100, "%A   %H:%M:%S %Z   %d %B %Y", localtime(&future));
   //
   // Print out now, and 1000 days from now.
   //
   cout << "\n"
           "      Now: " << s1 << "\n"
           "   Future: " << s2 << "\n"
           "\n";
}
