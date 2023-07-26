#include <stdio.h>

int main(void) {

int  c, other_cnt = 0, a_cnt = 0, b_cnt = 0, c_cnt = 0;

while ((c = getchar()) != EOF)
	if (c == 'a' || c == 'A')
		++a_cnt;
	else if (c == 'b' || c == 'B')
		++b_cnt;
	else if (c == 'c' || c == 'C')
		++c_cnt;
	else
		++other_cnt;
		
printf("%10s%10s%10s%10s\n\n",
		"a", "b", "c","others");
printf("%10d%10d%10d%10d\n\n",
		a_cnt, b_cnt, c_cnt, other_cnt);

		
/*printf("There are %d 'a's %d 'b's %d 'c's and %d other characters\n",
		a_cnt, b_cnt, c_cnt, other_cnt); */
		
	return 0;
}
