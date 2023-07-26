#include <stdio.h>
#include <time.h>

void   prn_struct_tm(struct tm *);

int main(void)
{
   struct tm   date = {0}, *tp;
   time_t      birthday, now;

   now = time(NULL);
   printf("\n%s%ld\n%s%s%s%s\n",
      "                     now = ", now,
      "             ctime(&now) = ", ctime(&now),
      "asctime(localtime(&now)) = ", asctime(localtime(&now)));
   /*
   // Right now in London.
   */
   printf("%s\n%s\n\n",
      "   ---",
      "   Greenwich mean time:");
   tp = gmtime(&now);
   prn_struct_tm(tp);
   /*
   // Right now, right here.
   */
   printf("%s\n%s\n\n",
      "   ---",
      "   Local time:");
   tp = localtime(&now);
   prn_struct_tm(tp);
   /*
   // Capture a specific birthday.
   */
   date.tm_hour = 88;
   date.tm_mday = 29;
   date.tm_mon = 6;
   date.tm_year = 77;
   birthday = mktime(&date);
   printf("%s%s\n",
      "   ---\n"
      "   After birthday = mktime(&date):\n"
      "\n"
      "   ", ctime(&birthday));
   prn_struct_tm(&date);
   return 0;
}

void prn_struct_tm(struct tm *tp)
{
   printf("%s%d\n%s%d\n%s%d\n%s%d\n%s%d\n%s%d\n%s%d\n%s%d\n%s%d\n\n",
      "   tm_sec   = ", tp -> tm_sec,
      "   tm_min   = ", tp -> tm_min,
      "   tm_hour  = ", tp -> tm_hour,
      "   tm_mday  = ", tp -> tm_mday,
      "   tm_mon   = ", tp -> tm_mon,
      "   tm_year  = ", tp -> tm_year,
      "   tm_wday  = ", tp -> tm_wday,
      "   tm_yday  = ", tp -> tm_yday,
      "   tm_isdst = ", tp -> tm_isdst);
}
