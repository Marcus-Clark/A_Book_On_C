#include <stdio.h>
#define  BOOLEX1 b1 || b2 || b3 || b4
#define	 BOOLEX2 b1 && b2 && b3 && b4
#define  BOOLEX3 !(!b1 || b2) && (!b3 || b4)


int main(void) {
	int 	b1, b2, b3, b4;		/*boolean variables */
	int		cnt = 0;
	
	printf("\n%5s%5s%5s%5s%5s%7s\n\n", /* headings */
		"cnt", "b1", "b2", "b3", "b4", "fct1");
	for (b1 = 0; b1 <= 1; ++b1)
		for (b2 = 0; b2 <= 1; ++b2)
			for (b3 = 0; b3 <= 1; ++b3)
				for (b4 = 0; b4 <= 1; ++b4)
					printf("%5d%5d%5d%5d%5d%6d\n",
						++cnt, b1, b2, b3, b4, BOOLEX3);
	putchar('\n');
		
		return 0;
	}
