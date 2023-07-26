#include <stdio.h>

enum day {sun, mon, tue, wed, thu, fri, sat};

typedef   enum day   day;

int main(void)
{
   day   val = sun;

   if (val == sun)
      printf("Today is Sunday.\n");
   else
      printf("Today is a working day.\n");
   return 0;
}
