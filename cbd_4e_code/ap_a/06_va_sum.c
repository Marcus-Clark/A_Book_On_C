#include   <stdarg.h>
#include   <stdio.h>

int va_sum(int cnt, ...);

int main(void)
{
   int      a = 1, b = 2, c = 3;

   printf("\n%s%d\n%s%d\n\n",
      "    First call: sum = ", va_sum(2, a, b),
      "   Second call: sum = ", va_sum(3, a, b, c));
   return 0;
}

int va_sum(int cnt, ...)           /* sum the arguments */
{
   int       i, sum = 0;
   va_list   ap;

   va_start(ap, cnt);              /* startup */
   for (i = 0; i < cnt; ++i)
      sum += va_arg(ap, int);      /* get next argument */
   va_end(ap);                     /* cleanup */
   return sum;
}
