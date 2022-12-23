#include <ctype.h>
#include <stdio.h>

int word_cnt(const char s[]);

int main(void)
{
	char s[] = "\0";
	
	printf("%d\n", word_cnt(s));
	return 0;
}


int word_cnt(const char s[])
{
	int cnt = 0;
	
	while (*s != '\0') {
		while (isspace(*s))
			++s;
		if (*s != '\0') {
			++cnt;
		while (!isspace(*s) && *s != '\0')
		++s;
	}
}
return cnt;
}
