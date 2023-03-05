#include <stdio.h>
#include <string.h>
char translate(char french[][30]);


int main(void) 
{
	int i, j;
	char french[][20] = { "oui", "non", "bonjour"} ;
	char english[][20] = {"yes", "no", "hello"}; 
	char tran[20] = {"bonjour"};
	for (i = 0; i < 3; ++i)	{
		for (j = 0; j < 3; ++j) {
			if(strcmp(tran, french[i]) == 0) {
				printf("%s\n", english[i]);
				break;
			}
			else 
				break;
			}
		}
		return 0;
	}
		
	

