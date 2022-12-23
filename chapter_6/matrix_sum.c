#include <stdio.h>

int sum(int (*a)[5]);

int main(void) {
	
	int a[3][5] = {	{1, 1, 1} ,
					{1, 1, 1, 1, 1}
				  };
	
	printf("sum of matrix elements: %d\n", sum(a));
	return 0;
	
}

int sum(int a[][5]) {
	int i, j, sum = 0;
	
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 5; ++j)
			sum += a[i][j];
	return sum;
}
