/* vulnerable1.c */

/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability, not by
 * modifying this code, but by providing a cleverly
 * constructed input. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 512

void greet(char *str)
{
    char greeting[32] = "Welcome ";

    /* The following allows buffer overflow */ 
    strcat(greeting, str);

    return;
}


int main()
{
    char str[BUFFER_SIZE];
	FILE *bf = fopen("badfile", "r");

    fread(str, sizeof(char), BUFFER_SIZE, bf);
    greet(str);

    printf("Returned properly: attack failed\n");
    return 1;
}
