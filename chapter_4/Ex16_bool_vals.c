#include <stdio.h>

/* print a table of values for some boolean functions */

int main(void) {
	int b1, b2, b3, b4, b5, b6, b7; /* boolean variables */
	int cnt = 0;
	
	printf("\n%5s%5s%5s%5s%5s%5s%7s%7s%11s\n\n", /* headings */
		"cnt", "b1", "b2", "b3", "b4", "b5", "b6", "b7", "majority");
	for (b1 = 0; b1 <= 1; ++b1)
		for (b2 = 0; b2 <= 1; ++b2)
			for (b3 = 0; b3 <= 1; ++b3)
				for (b4 = 0; b4 <= 1; ++b4)
					for (b5 = 0; b5 <= 1; ++b5)
						for (b6 = 0; b6 <= 1; ++b6)
							for (b7 = 0; b7 <= 1; ++b7)
						printf("%5d%5d%5d%5d%5d%5d%6d%7d%9d\n",
						++cnt, b1, b2, b3, b4, b5, b6, b7,
	b1 + b2 + b3 + b4 + b5 +b6 + b7 >= 4);
	putchar('\n');
		
		return 0;
	}
	
