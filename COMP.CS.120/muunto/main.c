#include <stdio.h>
#include "muunto.h"


int main(int argc, char *argv[])
{
    int i = 1;

    while ( i < argc ) {
        printf("%d: %s --> ", i, argv[i]);
        muunna(argv[i]);
        printf("%s\n", argv[i]);
        ++i;

    }
return 0;
}
