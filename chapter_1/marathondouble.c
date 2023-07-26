#include <stdio.h>

int main(void) 
{
	double 	miles, yards;
	double	kilometres;
	
	miles = 26;
	yards = 385;
	
	kilometres = 1.609 * (miles + yards /1760.0);
	printf("\nA marathon is %f kilometres. \n\n", kilometres);
	return 0;
	
}
