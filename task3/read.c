#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define FILE_NAME "output.txt"
#define MAX_INT 33


int main(){
	FILE fp = fopen(FILE_NAME, "r");
	char str[MAX_INT];
	int counter = 0;

	if(fp==NULL){
		printf("%s\n","Unable to open file");
		exit(0);
	}else{
		fgets(str,MAX_INT,fp);
		fprintf(stdout,"%s\n",str);
		fclose(fp);
	}
}