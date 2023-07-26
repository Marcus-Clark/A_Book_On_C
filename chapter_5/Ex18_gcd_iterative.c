#include <stdio.h>

int gcd(int a, int b);

int main(void) {
	int a, b;
	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);
	printf("gcd of %d and %d is %d\n", a, b, gcd(a, b));
	return 0;
}

int gcd(int a, int b) {
	
	int remainder;
	if(a==0)
	{
		return(b);
	}
	
	else if(b==0)
	{
		return(a);
	}
	
	else
	{
		while(b!=0)
		{
	
	 remainder = a % b;
	 a = b;
	 b = remainder ;
	
	}
	return(a);
	
}
}
