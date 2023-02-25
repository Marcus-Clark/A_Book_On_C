#include <stdio.h>

int main(void)
{
	char a, b, c,*p, *q, *r;
	a = 'a';
	b = 'b';
	c = 'c';
	p = &a;
	q = &b;
	r = &c;
	printf("a : %p b : %p c : %p *p : %p *q : %p *r : %p\n",  &a, &b, &c, p, q, r);
	
	return 0;
	
}
