#include <stdio.h>
/* model of how to use switch statement */
int main(void) {
int a_cnt = 0, b_cnt = 0, c_cnt = 0, other_cnt = 0;
char c = 'a';

switch(c) {
	case 'a':
		printf("Letter is %c\n", c);
		++a_cnt;
		break;
	case 'b':
		printf("Letter is %c\n", c);
		++b_cnt;
		break;
	case 'c':
		printf("Letter is %c\n", c);
		++c_cnt;
		break;
	default:
		printf("Letter is unrecognised\n");
		++other_cnt;
	}
	printf("a: %d b: %d c: %d  other: %d\n", a_cnt, b_cnt, c_cnt, other_cnt);
return 0;
}
