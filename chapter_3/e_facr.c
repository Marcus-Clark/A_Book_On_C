#include <stdio.h>
#include <math.h>
#include <stdint.h>

uint64_t factorial (uint64_t i)
{
    if (i==0)
        return 1;
    else
        return i*factorial(i-1);
}

int main(void)
{
    int n;
    double e = 1;
    double epsilon;

    printf("what is the value of epsilon: ");
    scanf("%lf", &epsilon);

    printf("what is the value of n: ");
    scanf("%d",&n);

    int i = 1;
    while(1)
    {
        e += 1.0/factorial(i++);

        if(i >= n && (fabs(e - M_E) < epsilon))
            break;
    }

    printf("e: %.20lf, calculated e: %.20lf, error: %.20lf, steps: %d\n", M_E, e, fabs(e-M_E), i);

    return 0;
}
