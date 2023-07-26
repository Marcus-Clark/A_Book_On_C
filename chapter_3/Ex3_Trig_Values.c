#include <stdio.h>
#include <math.h>

int main(void) {
double pi = M_PI;

double x = pi;
double h;
h = x / 2.0;
for (x = 0.0; x <= 2*pi; x += h)
	printf("%f %.15f\n", x, sin(x));
return 0;
}
