/* A family of pseudo random number generators. */

#define   INITIAL_SEED       17
#define   MULTIPLIER         25173
#define   INCREMENT          13849
#define   MODULUS            65536
#define   FLOATING_MODULUS   65536.0

static unsigned   seed = INITIAL_SEED;   /* external, but
                                            private to this file */

double probability(void)
{
   seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;
   return (seed / FLOATING_MODULUS);
}

unsigned random(void)
{
   seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;
   return seed;
}
