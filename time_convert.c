/* convert the source file timestamp into a localised date string */

#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
char * localised_time(char *filename);
int main(int argc, char *argv[] ) {
	FILE *ptr_fd;
    ptr_fd = fopen(argv[1], "r");
    printf("%s\n", localised_time( (char *)ptr_fd));
	return 0;
}

char * localised_time(char *filename) {
	struct tm *tm_ptr;
	struct stat stat_block;
	static char buffer[120];
	
	/* get the sourcefile's timestamp in time_t format */
	
	stat(filename, &stat_block);
	
	/* convert UNIX time_t into a struct tm holding local time */
	
	tm_ptr = localtime(&stat_block.st_mtime);
	
	/* convert the tm struct into s tring in local format */
	
	strftime(buffer, sizeof(buffer), "%a %b %e %T %Y", tm_ptr);
	
	return buffer;
}
	 

