#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int		i = 0, n;
	
	printf("%s\n%s", 
		"Some randomly distributed numbers will be printed.",
		"How many do you want to see? ");
		scanf("%d", &n);
		while (i++ < n) {
			if ((i % 6) == 0)
			putchar('\n');
		printf("%12d", rand());
	}
	printf("\n\n");
	return 0;
}
