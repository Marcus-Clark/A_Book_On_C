#include <stdio.h>
#define NUM (sizeof(available_resources) / sizeof(available_resources[0]))
/* NUM is the number of elements in the array *
 * without NUM we risk a seg fault due to overflowing 
 * available_resources[i] in the printf() statement */
int main(void)
{
	int i ;
	char *available_resources[] = {
		"color monitor",
		"big disk",
		
		"cray" /* whoa! No comma ;) */
		"on-line drawing routines",
		"mouse",
		"power cables",
		"wires",
		"plugs",
		"keyboards",
	};
	for (i=0; i < NUM; ++i) {
		printf("%s\n", available_resources[i]) ;
		} ;
	return 0;
}
