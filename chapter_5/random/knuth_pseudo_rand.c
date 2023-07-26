#include "rand.h"

static unsigned seed = INITIAL_SEED; /* external but private to this file */

unsigned random(void) {
	seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;
	return seed;
}

double probability(void) {
	seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;
	return (seed / FLOATING_MODULUS);
}
