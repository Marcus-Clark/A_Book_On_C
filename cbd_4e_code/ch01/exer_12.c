/* Convert seconds to minutes and seconds. */

#include <stdio.h>

int main(void)
{
   int   input_value, minutes, seconds;

   printf("Input the number of seconds:  ");
   scanf("%d", &input_value);
   minutes = input_value / 60;
   seconds = input_value % 60;
   printf( ... );
}
