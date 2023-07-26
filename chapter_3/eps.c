#include <float.h>
#include <stdio.h>

#define getName(var) #var
int main(void) {
	float f_eps = FLT_EPSILON;
	double d_eps = DBL_EPSILON;
	long double ld_eps = LDBL_EPSILON;
	double eps = 0.00000000000000000001;
	
	printf("float epsilon      : %0.19f\n", f_eps);
	printf("double epsilon     : %0.19f\n", d_eps);
	printf("long double epsilon: %0.19Lf\n", ld_eps);
	printf("eps                : %0.20f or %e\n\n",  eps, eps);
	
	
	double epsilon = eps;
	printf("The variable chosen to represent epsilon is: %s\n", getName(eps));
	if (1.0 < 1.0 + epsilon)
		printf("The test 1.0 < 1.0 + epsilon is true\n");
	else
		printf("The test 1.0 < 1.0 + epsilon is false\n");
	return 0;
}
