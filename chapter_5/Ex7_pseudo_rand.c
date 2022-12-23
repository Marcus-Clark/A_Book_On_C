#include <stdio.h>

#define	INITIAL_SEED		17
#define	MULTIPLIER			25173
#define INCREMENT			13849
#define MODULUS				65536
#define	FLOATING_MODULUS	65536.0

static unsigned seed = INITIAL_SEED; /* external but private to this file */

unsigned random(void);
double probability(void);

int main(void) {
int i;


	for (i = 0; i < 1000; ++i)
		printf("%f\n", probability());

	
	return 0;
}

unsigned random(void) {
	seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;
	return seed;
}

double probability(void) {
	seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;
	return (seed / FLOATING_MODULUS);
}
