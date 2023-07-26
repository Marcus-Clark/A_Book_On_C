// Simple C program to multiply two polynomials
#include <stdlib.h>
#include <stdio.h>

  
// A[] represents coefficients of first polynomial
// B[] represents coefficients of second polynomial
// m and n are sizes of A[] and B[] respectively
int *multiply(int A[], int B[], int m, int n)
{
   int *prod = malloc(n * sizeof(int));
  
   // Initialize the product polynomial
   for (int i = 0; i<m+n-1; i++)
     prod[i] = 0;
  
   // Multiply two polynomials term by term
  
   // Take every term of first polynomial
   for (int i=0; i<m; i++)
   {
     // Multiply the current term of first polynomial
     // with every term of second polynomial.
     for (int j=0; j<n; j++)
         prod[i+j] += A[i]*B[j];
   }
  
   return prod;
}
  
// A utility function to print a polynomial
void printPoly(int poly[], int n)
{
    for (int i=0; i<n; i++)
    {
       printf("%d", poly[i]);
       if (i != 0)
        
        printf("x^%d", i);
       if (i != n-1)
       
       printf(" + ");
    }
}
  
// Driver program to test above functions
int main()
{
    // The following array represents polynomial 5 + 10x^2 + 6x^3
    int A[] = {5, 0, 10};
  
    // The following array represents polynomial 1 + 2x + 4x^2
    int B[] = {1, 2, 4, 7};
    int m = sizeof(A)/sizeof(A[0]);
    int n = sizeof(B)/sizeof(B[0]);
  
    
    printf("First polynomial is ");
    printPoly(A, m);
    
    printf("\n second  polynomial is ");
    printPoly(B, n);
  
    int *prod = multiply(A, B, m, n);
  
    printf("\nProduct  polynomial is ");
    printPoly(prod, m+n-1);
  
    return 0;
}
