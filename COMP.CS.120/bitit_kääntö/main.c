#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bitit.h"


int main(void)
{
    signed char num = -33;
    signed char *ip;

    short int snum = 2015;
    short *sp;

    int inum = 2015;
    int *inp;

    long int lnum = 2015;
    long int *linp;



    ip = &num;
    sp = &snum;
    inp = &inum;
    linp = &lnum;
    kaannaScharBitit(ip);
    printf("\n");
    kaannaShortBitit(sp);
    printf("\n");
    kaannaIntBitit(inp);
    printf("\n");
    kaannaLongBitit(linp);



    return 0;
}
