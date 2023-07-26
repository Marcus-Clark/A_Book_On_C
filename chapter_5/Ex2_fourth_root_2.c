#include <math.h>
#include <stdio.h>

#define 	N	8

void heading(int n);
double fourth_root(int k);
void prn_table_of_fourth_roots(int n);

int main(void) {
	
	heading(N);
	prn_table_of_fourth_roots(N);
	
	return 0;
	
}

double fourth_root(int k) {
	
double result;
result = sqrt(sqrt(k));
return result;
	
}
void heading(int n) {
	int j;
	printf("Table of the first %d fourth roots\n\n", n);
	for (j = 1; j <= n; ++j) {
		printf("%9d",j); 
	}
	putchar('\n');
	}
void prn_table_of_fourth_roots(int n) {
	int i;
	
	for (i = 1; i <= n; ++i)
		printf("%9f", fourth_root(i));
	putchar('\n');
}
