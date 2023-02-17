#include "sum_sqr.h"

int main(void)
{
	printf("%s%.7f\n%s%.7f\n",
		"	First Computation: ", sum_square(f, 1, 1000000),
		"	Second Computation: ", sum_square(sin, 2, 13));
		
		return 0;
}
