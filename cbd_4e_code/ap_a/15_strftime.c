#include <iostream.h>
#include <time.h>

int main()
{
   char     s[100];
   time_t   now;

   now = time(NULL);

   cout << "\n";
   strftime(s, 100, "%H:%M:%S on %A, %d %B %Y", localtime(&now));
   cout << "   " << s << "\n\n";
   strftime(s, 100, "Week of the year: %U", localtime(&now));
   cout << "   " << s << "\n\n";
}
