#include <stdlib.h>
#include <stdio.h>
#include <math.h>  

int main(void) {
int expon;
float n = 6000000000;

float mant = frexpf(n, &expon);
printf("%g = %g * 2^%d\n", n, mant, expon);

return 0;
}
