/* Compute interest compounded yearly. */

#include <stdio.h>

double   compute(double principal, double rate, int nyears);
void     prn_instructions(void);
void     prn_results(double a, double p, double r, int n);

int main(void)
{
   double   amount;      /* principal + interest */
   double   principal;   /* beginning amount in dollars */
   double   rate;        /* example: 7% corresponds to 0.07 */
   int      nyears;      /* number of years */

   prn_instructions();
   for ( ; ; ) {
      printf("Input three items:  ");
      if (scanf("%lf%lf%d", &principal, &rate, &nyears) != 3)
         break;
      amount = compute(principal, rate, nyears);
      prn_results(amount, principal, rate, nyears);
   }
   printf("\nBye!\n\n");
   return 0;
}

double compute(double principal, double rate, int nyears)
{
   int      i;
   double   amount = principal;

   rate *= 0.01;        /* example: convert 7% to 0.07 */
   for (i = 0; i < nyears; ++i)
      amount *= 1.0 + rate;
   return amount;
}

void prn_instructions(void)
{
   printf("\n%s",
     "This program computes interest compounded yearly.\n"
     "Input principal, interest, and no. of years.\n"
     "For $1000 at 5.5% for 17 years here is example:\n\n"
     "Example input:  1000  5.5  17\n\n");
}

void prn_results(double a, double p, double r, int n)
{
   double   interest = a - p;     /* amount - principal */

   printf("\n%s%g%c\n%s%d%s\n\n",
      "Interest rate:  ", r, '%',
      "  Time period:  ", n, " years");
   printf("%s%9.2f\n%s%9.2f\n%s%9.2f\n\n",
      "Beginning principal:", p,
      "   Interest accrued:", interest,
      "       Total amount:", a);
}
