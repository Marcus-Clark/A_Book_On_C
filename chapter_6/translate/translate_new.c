#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char translate(char french[][30]);


int main(void) 
{
	char *buffer;
	size_t bufsize = 320;
	char *tran;
	
	buffer = (char *)malloc(bufsize * sizeof(char));
	if( buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	} 
	tran = getline(&buffer, &bufsize, stdin);
	int i, j;
	char french[][20] = { "oui", "non", "bonjour"} ;
	char english[][20] = {"yes", "no", "hello"}; 
	/*char tran[20] = {"bonjour"}; */
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
		
	

