#include <stdio.h>

int main(void)
{
	
	int i, j;
	
	int a[2][3] = {
		 {1,2,3},
		 {4,5,6} 
	 } ;
	 for (i = 0; i <2; ++i) {
		 for (j = 0; j < 3; ++j) {
			printf("%d", a[i][j]);
		}
	}
	printf("\n");
	printf("%d\n", a[1][1]);
	printf("%d\n", *(a[1] + 1));
	printf("%d\n", (*(a + 1))[1]);
	printf("%d\n", *((*(a+1)) + 1));
	printf("%d\n", *(&a[0][0] + 3*1 + 1));
	printf("\n");
	return 0;
}
	
