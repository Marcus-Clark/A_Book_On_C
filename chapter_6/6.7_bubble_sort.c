#include <stdio.h>
void bubble(int a[], int n);
void swap(int *, int *);

int main(void) {
	int i;
	int a[] = {7, 3, 66, 3, -5, 22, -77, 2};
	
	bubble(a, 8);
	printf("Sorted array: \n");
	for (i = 0; i < 8; ++i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

void swap(int *p, int *q) 
{
	int tmp;
	
	tmp = *p;
	*p = *q;
	*q = tmp;
}
void bubble(int a[], int n) { /* n is the size of a[] */
	int i, j;
	
	for (i = 0; i < n - 1; ++i)
		for (j = n - 1; j > i; --j)
			if (a[j-1] > a[j])
				swap(&a[j-1], &a[j]);
		
	}

