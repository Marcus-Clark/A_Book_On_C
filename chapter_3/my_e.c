#include <stdio.h>

double factorial (double i)
{
    if (i==0)
        return 1;
    else
        return i*factorial(i-1);
}

int main(void) {
	int n;
    double e = 1;
    

    printf("what is the value of n: ");
    scanf("%d",&n);

    int i = 1;
    while(1)
    {
        e += 1.0/factorial(i++);
        
        if(i >= n )
            break;
    }

    printf("e: %.20lf", e);

    return 0;
}
