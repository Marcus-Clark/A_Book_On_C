#include <stdio.h>

int main(void) {

    int i, denom;
    long double e, epsilon, term;

    printf("Enter epsilon: ");
    scanf("%Lf", &epsilon);

    for (i = 1, denom = 1, e = 1.0L, term = 1.0L; term > epsilon; i++) {
        term = (1.0 / (denom *= i));
        e += term;
    }
    printf("Approximation of e: %Lf\n", e);

    return 0;
}
