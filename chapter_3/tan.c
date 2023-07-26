#include <stdio.h>
#include <math.h>

int main(void) {
double pi = M_PI;
double h;
double x = pi;
h = x / 2.0;

	
printf("\nTan(x) in Radians\n");
	printf("Pi Radians         tan(x)\n");
for (x = 0.0; x <= 2*pi; x += h)
	printf("%f    %.0f\n", x / pi, tan(x));
	

return 0;
}
