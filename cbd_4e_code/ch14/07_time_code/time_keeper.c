#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define   MAXSTRING   100

typedef struct {
   clock_t   begin_clock, save_clock;
   time_t    begin_time, save_time;
} time_keeper;

static time_keeper   tk;     /* known only to this file */

void start_time(void)
{
   tk.begin_clock = tk.save_clock = clock();
   tk.begin_time = tk.save_time = time(NULL);
}

double prn_time(void)
{
   char     s1[MAXSTRING];
   char     s2[MAXSTRING];
   int      field_width;
   int      n1;
   int      n2;
   double   clocks_per_sec = (double) CLOCKS_PER_SEC;
   double   user_time;
   double   real_time;

   user_time = (clock() - tk.save_clock) / clocks_per_sec;
   real_time = difftime(time(NULL), tk.save_time);
   tk.save_clock = clock();
   tk.save_time = time(NULL);
   /*
   // Print the values found, and do it neatly.
   */
   sprintf(s1, "%.1f", user_time);
   n1 = strlen(s1);
   sprintf(s2, "%.1f", real_time);
   n2 = strlen(s2);
   field_width = (n1 > n2) ? n1 : n2;
   printf("%s%*.1f%s\n%s%*.1f%s\n\n",
      "   User time: ", field_width, user_time, " seconds",
      "   Real time: ", field_width, real_time, " seconds");

   return user_time;
}

double prn_total_time(void)
{
   char     s1[MAXSTRING];
   char     s2[MAXSTRING];
   int      field_width;
   int      n1;
   int      n2;
   double   clocks_per_sec = (double) CLOCKS_PER_SEC;
   double   total_user_time;
   double   total_real_time;

   total_user_time = (clock() - tk.begin_clock) / clocks_per_sec;
   total_real_time = difftime(time(NULL), tk.begin_time);
   tk.save_clock = clock();
   tk.save_time = time(NULL);
   /*
   // Print the values found, and do it neatly.
   */
   sprintf(s1, "%.1f", total_user_time);
   n1 = strlen(s1);
   sprintf(s2, "%.1f", total_real_time);
   n2 = strlen(s2);
   field_width = (n1 > n2) ? n1 : n2;
   printf("%s%*.1f%s\n%s%*.1f%s\n\n",
      "   Total user time: ", field_width, total_user_time, " seconds",
      "   Total real time: ", field_width, total_real_time, " seconds");

   return total_user_time;
}
