#include <stdio.h>
#include <math.h>

int main(void) {
double pi = M_PI;
double h;
double x = pi;
h = x / 2.0; /* step size of pi/2 radians */
printf("Sine(x) in Radians\n");
	printf("Pi radians         sin(x)\n");
for (x = 0.0; x <= 2*pi; x += h)
	printf("%f    %.15f\n", x / pi, sin(x));
	
printf("\nCosine(x) in Radians\n");
	printf("Pi radians         cos(x)\n");
for (x = 0.0; x <= 2*pi; x += h)
	printf("%f    %.15f\n", x / pi, cos(x));
	
printf("\nTan(x) in Radians\n");
	printf("Pi radians         tan(x)\n");
for (x = 0.0; x <= 2*pi; x += h)
	printf("%f    %.0f\n", x / pi, tan(x));
return 0;
}
