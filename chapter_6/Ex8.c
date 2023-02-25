#include <stdio.h>

typedef unsigned long ulong;

int main(void)
{
	char 			*pc = NULL;
	int				*pi = NULL;
	double 			*pd = NULL;
	long double 	*pld = NULL;
	
	printf("%5lu%5lu\n%5lu%5lu\n%5lu%5lu\n",
		(ulong)(pc + 1), (ulong)(pi + 1),
		(ulong)(pd + 1), (ulong)(pld + 1),
		(ulong)(pc + 3), (ulong)(pld + 3));
	return 0;
	
}
