#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mjonot.h"

char ** kopioi_mjt(char **mjt, size_t lkm)
{
    int i = 0;
    int max_i = lkm - 1;
    char **kopio = malloc(lkm*sizeof(char *));

    while (i <= max_i)
    {
        int sub_i = 0;
        size_t length = strlen(mjt[i]);

        char *kopio_sana = malloc(length + 1);
        strcpy(kopio_sana, mjt[i]);

        kopio[i] = kopio_sana;

        ++i;
    }

    return kopio;
}
