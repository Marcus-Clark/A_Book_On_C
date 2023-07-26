#include <stdio.h>

int main(void)
{
	int i, j;
	int *p, *q;
	i = 3;
	j = 4;
	p = &i;
	p = &*&i;
	i = (int) p;
	/*q = &p *q = &j; */
	/*i = (*&)j; */
	i = *&*&j;
	i = *p++ + *q;
	
return 0;	
}
