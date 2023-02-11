#include <stdio.h>

struct s_tag {int a[100]; } ;
struct s_tag orange, lime, lemon;

struct s_tag twofold(struct s_tag s) {
	int j;
	for (j = 0; j < 100; j++) s.a[j] *=2;
	return s;
}

int main(void) {
	int i;
	
	for (i = 0; i < 100; i++) lime.a[i] = 8;
	lemon = twofold(lime);
	orange = lemon; /* assigns entire struct */
	printf("%d\n", lemon.a[1]);
	
	return 0;
}
