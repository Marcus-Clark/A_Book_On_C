#include <stdio.h>
#include <math.h>
int main(void) {

double x;
double n;

for (n = 1; n < 9999; ++n) {
	x = pow(1 + 1/n, n);
	printf("%f\n", x);
}
 
	
return 0;

}

