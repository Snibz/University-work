#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bitit.h"

int main(int argc, char *argv[])
{

    signed char x = -33;
    short int y = 2015;
    int z = 2015;
    long int i = 2015;

    scharBitit(x);
    shortBitit(y);
    intBitit(z);
    longBitit(i);


    return 0;
}
