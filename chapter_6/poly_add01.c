/* Naive C program to add two polynomials */
#include <stdio.h>
#include <stdlib.h>
 
/* A function to return maximum of two integers */
int max(int m, int n) { return (m > n) ? m : n; }
 
/*A[] represents coefficients of first polynomial
* B[] represents coefficients of second polynomial
* m and n are sizes of A[] and B[] respectively */

int* add(int A[], int B[], int m, int n, int* sum1)
{
	
   
   
 /* Initialize the product polynomial */
    for (int i = 0; i < m; i++)
        sum1[i] = A[i];
	
    /*Take every term of first polynomial */
    for (int i = 0; i < n; i++)
        sum1[i] += B[i];
 
    return sum1;
    
}
 
/* A  function to print a polynomial */
void printPoly(int poly[], int n)
{
    for (int i = 0; i < n; i++) {
		printf("%d", poly[i]);
        if (i != 0)
            printf("x^%d", i);
        if (i != n - 1)
            printf("%s", " +  ");
    }
}
 

int main()
{
    /* The following array represents polynomial 5 + 10x^2 +
    *6x^3 */
    int A[] = { 5, 0, 10, 6 };
 
    /* The following array represents polynomial 1 + 2x +
    * 4x^2 */
    int B[] = { 1, 2, 4 };
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);
    
	int* sum1 = malloc(max(n, m) * sizeof(int)); 
    
    printf("First polynomial is  \n");
    printPoly(A, m);
  
    printf("\nSecond polynomial is  \n");
    printPoly(B, n);
 
    int* sum = add(A, B, m, n, sum1);
    int size = max(m, n);
 
    
    printf("\nSum polynomial is  \n");
    printPoly(sum, size);
	free(sum1);
	free(sum);
    return 0;
}
