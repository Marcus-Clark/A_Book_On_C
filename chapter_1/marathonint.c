#include <stdio.h>

int main(void) 
{
	int 	miles, yards;
	float	kilometres;
	
	miles = 26;
	yards = 385;
	
	kilometres = 1.609 * (miles + yards /1760); /*wrong */
	printf("\nA marathon is %f kilometres. \n\n", kilometres);
	return 0;
	
}
