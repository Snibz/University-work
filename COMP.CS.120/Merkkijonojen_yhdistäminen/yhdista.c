#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "yhdista.h"



char *yhdista(const char *mj, ...)
{
    size_t size = 2;
    int chars_copied = 0;
    int new_mj_i = 0;

    va_list pl;

    char *new_mj = malloc(size*sizeof(char));
    va_start(pl, mj);
    while(mj != NULL)
    {
        int i = 0;
        while(mj[i] != '\0')
        {

            while(chars_copied >= size)
            {
                size = 2 * size;
                new_mj = realloc(new_mj, size*sizeof(char));
            }

            new_mj[new_mj_i] = mj[i];
            i += 1;
            new_mj_i += 1;
            chars_copied += 1;

        }
        mj = va_arg(pl, char *);


    }
    va_end(pl);
    size = chars_copied + 1;

    new_mj = realloc(new_mj, size*sizeof(char));
    return new_mj;
}
