#include <stdio.h>
#include <math.h>

int main(void) {
	
	int 	a, b, c, disc, i_disc;
	double	root_disc, root_i_disc;
	
	printf("Enter values for a, b and c\n");
	scanf("%d %d %d", &a, &b, &c);
	
	disc = b * b - (4 * a * c);
	if (disc >= 0) {
		root_disc = sqrt(disc);
		printf("positive discriminant is %d\n", disc);
		printf("sq rt of positive discriminant is %f\n", root_disc);
	} else
		i_disc = -1 * disc;
			root_i_disc = sqrt(i_disc);
		printf("Negative disc is %d\n", i_disc);
		printf("sq rt of negative discriminant is i*%f\n", root_i_disc);

return 0;
}
	
	
