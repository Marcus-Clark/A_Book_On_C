#include <stdio.h>
void bubble(int a[], int n);
void swap(int *, int *);
void printArray(int arr[], int size);

int main(void) {
	
	int a[] = {7, 3, 66, 3, -5, 22, -77, 2, 0, 77, 5, 23, 76};
	int n = sizeof(a) / sizeof(a[0]);
	bubble(a, n);
	printf("Sorted array: \n");
    printArray(a, n);
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
	/* modified bubble - stops when all numbers swapped */
	int i, j;
	int swapped;
	for (i = 0; i < n - 1; ++i)
	{
	swapped = 0; 
		for (j = 0; j < n - i - 1; ++j)
		{
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);	
                swapped = 1;
			}
         }
      if (swapped == 0)
		break;
    }	
	}
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
