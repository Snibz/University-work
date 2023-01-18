#include <stdio.h>
#include <stdlib.h>
#include "luku.h"



char *lueKunnes(FILE *virta, char erotin, size_t *pituus)
{
    size_t kap = 1;
    char *puskuri = malloc(kap * sizeof(char));

    size_t pit = 0;
    int index = 0;

    int i = 0;
    int flag = 1;
    int chari = erotin;

    while( flag == 1 )
    {
        i = fgetc(virta);

        if(i == chari || i == EOF)
        {
            /* Reading ends */
            if(pit > 0 || i == chari)
            {
                kap = pit + 1;
                puskuri = realloc(puskuri, kap);
                /* puskuri[pit] = '\n'; */
            }
            else
            {
                puskuri = realloc(puskuri, 0);
            }
            flag = 0;
        }
        else
        {
            /* i is not the separator or end of file */
            char current = i;
            if(pit == kap)
            {
                kap = 2*kap;
                puskuri = realloc(puskuri, kap);
            }
            puskuri[index] = current;
            pit += 1;
            index += 1;

        }

    }
    *pituus = pit;
    return puskuri;


}
