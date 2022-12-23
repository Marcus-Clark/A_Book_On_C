#include <stdio.h>
#include <math.h>
/* possibly more in the style of how Ex3 was intended */

int main(void) {
	double 	two_pi = 2.0 * M_PI; /* in math.h */
	double 	h      = 0.2;		 /* step size */
	double  x;
	
	for (x = 0.0; x < two_pi; x += h)
		printf("%5.1f: %.15f\n",
		x, sin(x) );
	return 0;
}
