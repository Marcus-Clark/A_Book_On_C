#include <math.h>
#include <stdio.h>
int main() {
    double a, b, c, discriminant, root1, root2, realPart, imagPart;
    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

	if (a == 0 && b == 0) {
		printf("extremely degenerate case\n");
	
	} else if (a == 0 && b != 0) {
		printf("degenerate case\n");
		root1 = - (c / b);
		printf("Has one root: %lf\n", root1);
	} else if (discriminant > 0) {
		printf("Has two real roots\n");
		root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("root1 = %.2lf and root2 = %.2lf", root1, root2);
	} else if (discriminant == 0) {
		printf("Has multiple roots, which are real and equal\n");
		root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("root1 = %.2lf and root2 = %.2lf", root1, root2);
	} else if (discriminant < 0) {
		printf("Has two complex roots\n");
		realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);
        printf("root1 = %.2lf+%.2lfi and root2 = %.2f-%.2fi", realPart, imagPart, realPart, imagPart);
	}
		return 0;
	}
