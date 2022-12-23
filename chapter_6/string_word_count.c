#include <stdio.h>
#include <ctype.h>
#include <string.h>
int word_cnt(const char *s);
int main(void)
{
	char *s = "Hello world. This is a message.";
	
	printf("The number of words in string: %d\n", word_cnt(s));
	
	
	return 0;
}

/* count the number of word in a string */

int word_cnt(const char *s)
{
	int cnt = 0;
	
	while (*s != '\0') {
		while (isspace(*s))		/* skip white space */
			++s;
		if (*s != '\0') {		/*found a word */
			++cnt;
			while (!isspace(*s) && *s != '\0')	/*skip the word */
				++s;
			}
		}
		return cnt;
	}
