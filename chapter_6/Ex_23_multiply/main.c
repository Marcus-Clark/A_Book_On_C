#include "multiply.h"

int main(){
    char a[MAX];
    char b[MAX];
    char *c;
   
    printf("Enter the first number : ");
    scanf("%s",a);
    printf("Enter the second number : ");
    scanf("%s",b);
    printf("Multiplication of two numbers : ");
    c = multiply(a,b);
    printf("%s\n",c);
    return 0;
}
