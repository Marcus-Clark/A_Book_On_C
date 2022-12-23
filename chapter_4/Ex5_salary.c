#include <stdio.h>
#include <ctype.h>
int main(void) {

double salary, fwt, swt, sum_sal, sum_fwt, sum_swt;
printf("Enter your salary, enter 0 to exit: \n");
while (scanf("%lf", &salary) == 1) {
	if (salary <= 0.0)
		break;
	fwt = 0.17 * salary;
	swt = 0.03 * salary;
	sum_sal += salary;
	sum_fwt += fwt;
	sum_swt += swt;
	printf("%lf %lf %lf\n", salary, fwt, swt);
}
printf("sum of salaries entered is: %lf\n", sum_sal);
printf("sum of fwt entered is: %lf\n", sum_fwt);
printf("sum of swt entered is: %lf\n", sum_swt);
return 0;
}
