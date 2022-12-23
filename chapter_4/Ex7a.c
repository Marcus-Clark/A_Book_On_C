#include <stdio.h>
/*subtle error */
int main(void) {
	int i;
	
	if (i = 2)  /* this is an assignment, not an equality */
		printf("Some even numbers: %d %d %d\n", i, i + 2, i + 4);
		
	
	
return 0;
}
