#include <math.h>
#include <stdio.h>

#define 	N	7

double fourth_root(int k);
void prn_table_of_fourth_roots(int n);

int main(void) {
	
	
	prn_table_of_fourth_roots(N);
	
	return 0;
	
}

double fourth_root(int k) {
	
double result;
result = sqrt(sqrt(k));
return result;
	
}
void prn_table_of_fourth_roots(int n) {
	int i;
	
	for (i = 1; i <= n; ++i)
		printf("%9f", fourth_root(i));
	putchar('\n');
}
