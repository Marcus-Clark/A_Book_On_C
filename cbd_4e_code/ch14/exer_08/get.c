#include "fortune.h"

// ---
// Get an integer from stdin and store it in n.
// The value of n must satisfy
//
//    min <= n       and       n <= max
//
//

no_yes get_answer(cchr* line)
{
   cchr*   p;

   for (p = line; isspace(*p); ++p)
      ;
   if (*p == 'n' || *p == 'N')
      return no;
   return yes;
}


int get_int_reply(int min, int max)
{
   char    line[maxline];
   cchr*   p;
   int     n;

   cin.getline(line, maxline);
   if (!cin) {
      cout << "\n   ERROR: Reply not found - bye!\n\n";
      exit(1);
   }
   istrstream   iss(line);
   iss >> n;
   if (!iss) {
      cout << "\n"
              "ERROR: Integer not found.\n"
              "       Do it again.\n"
              "\n"
              "How many fortunes containing this phrase do you want? ";
      return get_int_reply(min, max);
   }
   for (p = line; isspace(*p); ++p)
      ;
   if (*p == '+' || *p == '-')
      ++p;
   while (isdigit(*p))
      ++p;
   for ( ; isspace(*p); ++p)
      ;
   if (*p != '\0') {
      cout << "\n"
              "ERROR: You must input nothing but an integer\n"
              "       Do it again.\n"
              "\n"
              "How many fortunes containing this phrase do you want? ";
      return get_int_reply(min, max);
   }
   if (n < min || n > max) {
      cout << "\n"
              "ERROR: You must input an integer between "
           << min << " and " << max << ".\n"
              "       Do it again.\n"
              "\n"
              "How many fortunes containing this phrase do you want? ";
      return get_int_reply(min, max);
   }
   return n;
}

// ---
// To read about strftime(), see
// page 599 in Appendix A.
//

void get_time(char* s)
{
   cchr*    format = "%A   %H:%M:%S %Z   %d %B %Y";
   time_t   now;

   now = time(NULL);

   strftime(s, maxstring, format, localtime(&now));
}
