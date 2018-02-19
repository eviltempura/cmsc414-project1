/* guesser.c */

#include <stdio.h>    /* for printf() */
#include <stdlib.h>   /* for EXIT_SUCCESS */

int your_fcn()
{
    // #include <string.h>
    // char buffer[4] = "";
    // char eip[4] = "";
    // unsigned int haha;
    // strcpy(buffer,"abc");
    // strncpy(eip,buffer+20,4);
    // haha = ((*eip)<<24) | ((*eip+1)<<16) | ((*eip+2)<<8) | (*eip+3);
    // printf("%x\n", haha);
    // return 0;
    char buff[4];
    int *eip = &(buff[4]) + 8;
    (*eip)+=12;
    return 233;
}

int main()
{
    int mine = 0;
    int yours = 0;

    yours = your_fcn();
    mine = yours + 1;

    if(mine > yours)
        printf("You lost!\n");
    else
        printf("You won!\n");

    return EXIT_SUCCESS;
}
