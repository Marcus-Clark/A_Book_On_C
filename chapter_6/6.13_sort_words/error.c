#include "sort.h"

void error_exit_calloc_failed(void)
{
	printf("%s",
			"Error: The call to calloc() failed to\n"
			"	allocate the requested memory - bye!\n");
		exit(1);
	}
	
void error_exit_too_many_words(void)
{
	printf("Error: At most %d words can be sorted - bye!\n", N);
	exit(1);
}

void error_exit_word_too_long(void)
{
	printf("%s%d%s",
		"Error: A word with more than ", MAXWORD, "\n"
		"	characters was found - bye!\n");
	exit(1);
}
