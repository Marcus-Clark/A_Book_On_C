#include <stdio.h>

int main(void) {

int a;
double x0 , x1;

printf("Enter a number:  ");
scanf("%d", &a);
printf("\n");

x0 = 1;
x1 = a ;
while (x0 != x1) {
	x0 = x1;
	x1 = 0.5 * (x1 + a / x1);
	
	printf("%0.15f\n", x1);
}

return 0;

}

