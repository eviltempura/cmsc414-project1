/*read.c*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define FILE_NAME "output.txt"
#define MAX_INT 33


int main(){

	FILE *file_ptr = fopen(FILE_NAME, "r");
	char str[MAX_INT];
	int c, counter = 0;

	if (file_ptr == NULL){
		printf("Unable to open file.\n");
		exit(0);
	}else{
		fgets(str, MAX_INT, file_ptr);
		fprintf(stdout,"%s\n",str);
		fclose(file_ptr);
	}

	return 1;
}