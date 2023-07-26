#include <stdio.h>
#include <ctype.h>

int my_word_cnt(const char *s);
size_t my_strlen(const char *s);
int main(void) {
	
	/*const char *s = "One two three four"; */
	 const char *s ;
	 s = "One two three four";
	printf("Number of words in string is: %d\n", my_word_cnt(  s));
	printf("The length of the string is: %zu\n", my_strlen(s));
	return 0;
}

/*my_word_cnt: a function to count words in a string */


	int my_word_cnt(const char *s) {
		int cnt = 0;
		
		while (*s != '\0') { 					/* skip white space */
			while (isspace(*s))
				++s;
			if (*s != '\0') {					/* found a word */
				++cnt;
			while (!isspace(*s) && *s != '\0')	/* skip the word */
				++s;
			}
		}
		return cnt;
	}
	/* my_strlen: a funcrion to count characters in a string */
	size_t my_strlen(const char *s) {
		size_t	n;
		
		for (n = 0; *s != '\0'; ++s)
			++n;
		return n;
	}
