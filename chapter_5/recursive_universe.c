#include <stdio.h>
int i = 0;
int main(void) {
	
	i++;
	while (i < 7) {
	printf("The universe is never ending!");
	main(); 
}
	return 0;
}
