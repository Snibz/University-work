#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "pvm_ero.h"

int main(void)
{

    pvm_ero("26.04.2016", "09.5.2013");
    pvm_ero("29.2.1900", "29.2.2000");
    pvm_ero("05.08.2016", "21.08.2016");
    pvm_ero("010.8.1957", "15.7.1930");

    return 0;
}
