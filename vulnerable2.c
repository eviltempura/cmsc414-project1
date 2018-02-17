/* vulnerable2.c */

/* This program also has a buffer overflow vulnerability. 
 * Our task is to exploit this vulnerability, even when
 * ASLR is turned on. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void echo_info()
{
    char age[32];
    char name[32];

    /* These are pipes to allow for 'communication' between
     * vulnerable2 and exploit2; you can ignore them. */
	FILE *out = fopen("f0", "w");
	FILE *in = fopen("f1", "r");

	/* Read in the user's name */
    fscanf(in, "%s", age);

	/* Echo it right back to them */
    fprintf(out, age);
    fprintf(out, "\n");
	fflush(out);

	/* Read in the user's name */
	fscanf(in, "%s", name);
}


int main()
{
    echo_info();

    printf("Returned properly: attack failed\n");
    return 1;
}

