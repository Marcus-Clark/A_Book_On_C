#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAXWORD	50 		/* max word size */
#define	N		30000		/*array of size w[] */ 

void	error_exit_calloc_failed(void);
void	error_exit_too_many_words(void);
void	error_exit_word_too_long(void);
void	sort_words(char *w[], int n);
void	swap(char **p, char **q);
void	wrt_words(char *w[], int n);
