#include <stdarg.h>
#include <stdio.h>

double   max(double x, double y);
int      sum(int a, int b, int c);
void     vargs_report(char *fct_name, char *cntrl_str, ...);

int main(void)
{
   sum(1, 2, 3);
   max(5.5, 7.7);
   vargs_report("sum", "%d, %d, %d", sum);
   vargs_report("max", "%.1f, %.1f\n", max);
   return 0;
}

double max(double x, double y)
{
   return ((x > y) ? x : y);
}

int sum(int a, int b, int c)
{
   return (a + b + c);
}

void vargs_report(char *fct_name, char *cntrl_str, ...)
{
   va_list   args;

   va_start(args, cntrl_str);
   printf("%s\n%s%s\n%s",
      "---",
      "Function name: ", fct_name,
      "    Arguments: ");
   vprintf(cntrl_str, args);
   putchar('\n');
}
