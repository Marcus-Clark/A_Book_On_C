#include <stdio.h>
#include <ctype.h>
#define N 4;
int main(void)
{
	int cnt;
	char *french[100] = {"oui" , "non"};
	char *english[100] = {"yes", "no"};
	
	char *text[100] = {"non", "bonjour", "yes"};
	
	while (**text != '\0') {
		while (isspace(*text))
			++*text;
		if (**text != '\0') {
			++cnt;
			while (!isspace(*text) && **text != '\0')
				++*text;
			}
		}
		printf("%d\n", cnt);
	return 0;
	
}
	

