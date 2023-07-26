#include <stdio.h>
#define MAXSTRING 100
#define MAXLINE 1000
int wordget(char word[], int maxline);
void wrt_it(void);


int main(void) {
	
	char word[MAXLINE];
	printf("Enter\n");
	while (wordget(word, MAXLINE) > 0 ) {
	wrt_it();
	}  
	
	printf("\n\n");

	
	return 0;
}

void wrt_it(void) {
	
	int i, c;
	char string[MAXSTRING];
	
	i = 0;
	while ((c = getchar()) != '\n') {
		string[i] = c;
		++i;
	}
	while (i >= 0) {
		putchar(string[i]);
		--i;
		}
			
	}
/*wordget*/
int wordget(char s[], int lim) {

	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) !=EOF && c != ' '; ++i)
		if (i < lim) {
			s[j] = c;
			++j;
		}
	if (c == ' ') {
		s[j] = c;
		++j;
		++i;
	}
	s[j] = '\0';
	return i;
}
