#include <stdio.h>

int main(void)
{
	int i = 9, *p;
	char k = 'c',*c, *s;
	char str[] = "hello";
	
	p = &i;
	c = &k;
	
	
	printf("%d %p\n", *p, p);
	printf("%c %p\n", *c - 2, c);
	printf("%s\n", str);
	return 0;
}
