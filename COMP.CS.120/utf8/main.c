#include <stdio.h>
#include "utf8.h"

int main(void)
{


    unsigned char utf8[5];
    unsigned int i = 228;

    utf8_koodaa(i, utf8);
    printf("%s\n", utf8);

  return 0;
}
