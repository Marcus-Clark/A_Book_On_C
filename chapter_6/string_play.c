#include <stdio.h>
#include <string.h>

int main(void) {
	
	char s1[] = "beautiful big sky country";
	char s2[] = "how now brown cow";
	
	printf("length of s1 is %ld\n", strlen(s1));
	printf("length of s2 is %ld\n", strlen(s2));
	printf("length of (s2 + 8) is %ld\n", strlen(s2 + 8));
	printf("strcmp(s1,s2) is %d\n", strcmp(s1,s2));
	
	printf("s1 + 10 %s\n", s1 + 10);
	
	strcpy(s1 + 10, s2 + 8);
	strcat(s1, "s!");
	printf("%s", s1);
	return 0;
	
}
