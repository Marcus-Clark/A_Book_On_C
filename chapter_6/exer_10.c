#include <stdio.h>

int *   change_it(int []);

int main(void)
{
   int    a[5], *p;
	p = a;
   printf("p has the value %p\n",  p);
   printf("p has the value %d\n",  *p);
   p = change_it(a); 				/* change_it() called differently than in book */
    
   printf("p has the value %p\n", p);
   printf("p has the value %d\n",  *p);
   return 0;
}
/* This version of change_it() actually changes a */
int * change_it(int a[])
{
   int   i = 777, *q = &i;

   a = q;     /* a is assigned a different value */
   return a;
}
