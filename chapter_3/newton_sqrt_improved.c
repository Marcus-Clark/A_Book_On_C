#include <stdio.h>

int main(void) {

int a, cnt;
double x0 , x1;

printf("Enter a number:  ");
scanf("%d", &a);
printf("\n");

cnt = 0;
x0 = 1;
x1 = a ;
printf("sqrt of a           error check\n");
while (x0 != x1) {
	x0 = x1;
	x1 = 0.5 * (x1 + a / x1);
	++cnt;
	printf("%0.15f  %0.15f     %7d\n", x1, a - x1 *x1, cnt);
	
}
	
return 0;

}

