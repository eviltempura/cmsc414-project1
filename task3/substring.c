#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	char buffer[512];
	char str[33];
	char substr[33];
	char first[3];
	char last[3];
	int strlen;
	int ifirst;
	int ilast;
	char c;
	int i = 0;
	int j = 0;

	fgets(buffer,512,stdin);

	//read the string
	c = buffer[i];
	while(i<32 && c!=' ' && c!='\t' && c!='\n'){
		str[i] = c;
		c = buffer[++i];
	}
	str[i] = '\x0';
	strlen = i;

	//get rid of extra string
	while(i<511 && c!=' ' && c!='\t' && c!='\n'){
		c = buffer[++i];
	}

	//get rid of white spaces
	while(i<511 && (c==' ' || c=='\t' || c=='\n')){
		c = buffer[++i];
	}

	//read the second part
	while(i<511 && j<2 && isdigit(c)!=0){
		first[j++] = c;
		c = buffer[++i];
	}
	first[j] = '\x0';

	//check size of the second part
	c = buffer[i];
	if(c!=' ' && c!='\t' && c!='\n'){
		printf("%s\n","Invalid input");
		exit(1);
	}

	//get rid of white spaces
	while(i<511 && (c==' ' || c=='\t' || c=='\n')){
		c = buffer[++i];
	}

	//read the third part
	j = 0;
	while(i<511 && j<2 && isdigit(c)!=0){
		last[j++] = c;
		c = buffer[++i];
	}
	first[j] = '\x0';

	//check size of the third part
	c = buffer[i];
	if(c!=' ' && c!= '\t' && c!='\n'){
		printf("%s\n","Invalid input");
		exit(1);
	}

	ifirst = atoi(first);
	ilast = atoi(last);

	if(!(ifirst>=0 && ifirst<=ilast && ilast<32)){
		printf("%s\n","Invalid input");
		exit(1);
	}

	FILE *fp;
	fp = fopen("output.txt","w");

	j = 0;
	for(j;j<(ilast-ifirst+1);j++){
		fprintf(fp,"%c",str[ifirst+j]);
	}
}