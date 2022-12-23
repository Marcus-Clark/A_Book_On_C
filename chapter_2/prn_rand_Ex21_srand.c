#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int		i, n;
	
	srand(time(NULL));
	printf("%s\n%s", 
		"Some randomly distributed numbers will be printed.",
		"How many do you want to see? ");
		scanf("%d", &n);
		for (i=0; i < n; ++i) {
			if ((i % 5) == 0)
			putchar('\n');
		printf("%12d", rand());
	}
	printf("\n\n");
	return 0;
}
