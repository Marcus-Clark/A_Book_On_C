#include <stdio.h>

int main(void)
{
	char 	*format = "%p   %d %d %d\n";
	char 	*my_format = "%d\n";
	int i	= 3;
	int	*p = &i;
	
	printf(format, p, *p + 7, 3 * **&p + 1, 5 * (p -(p -2)));
	printf(my_format, p - (p - p));
	printf(my_format, p - 2);
	printf(my_format, p );
	
	return 0;
	
}
/* In this case p - p is zero 
 * and 5 * (0 -(0 -2) = 5 * 2	
 * page 255						*/
