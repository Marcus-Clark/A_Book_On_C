#include <stdio.h>

int main(void) {
	int left_cnt = 0, right_cnt = 0;     /*variables to keep track of braces */
	int c;
	/*char out = '?'; */
	while ((c = getchar()) != EOF) {
			if (c == '{')
				++left_cnt;
			else if (c == '}')
				++right_cnt;
					if (left_cnt >= right_cnt)
						putchar(c);
					else if  (right_cnt > left_cnt)
						putchar('?');
	}
putchar('\n');
			
if (left_cnt > right_cnt)
printf("Error %d missing right braces\n", left_cnt - right_cnt);
	
		
putchar('\n');
		
		
			
	return 0;
	
}
