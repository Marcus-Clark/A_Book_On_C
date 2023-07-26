#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void revstr(char *str) {
	char tmp, *src, *dst;
	size_t len;
	if (str != NULL) {
		len = strlen(str);
		if (len > 1) {
			src = str;
			dst = src + len -1;
			while(src < dst) {
				tmp = *src;
				*src++ = *dst;
				*dst-- = tmp;
				}
			}
			
		}
	}
	
int main(void) {
	FILE *fp = fopen("/usr/share/dict/words", "r");
	if(fp == NULL) {
		perror("Unable to open file!");
		exit(1);
	}
	char dw[128] = "";
	char sdw[128] = "";
	
	while(fgets(dw, sizeof(dw), fp) != NULL) {
		dw[strlen(dw) -1] = '\0';
		if (strlen(dw) > 1 ) {
			strcpy(sdw, dw);
			revstr(dw);
			if (strcmp(sdw, dw) == 0) {
				printf("%s\n", sdw);
			}
		}
	}
	fclose(fp);
	return 0;
	}
