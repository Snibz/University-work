#include <stdio.h>
#include <stdlib.h>
#include "tulostus.h"


void tulostaDblTaulu(double *taulu, size_t lkm, const char *taulNimi,
                     int tarkkuus, const char *tiedNimi)
{
    int taulu_i = 0;
    FILE *fyle = fopen(tiedNimi, "w");


    for(taulu_i=0; taulu_i<lkm; ++taulu_i)
    {
        fprintf(fyle, "%s[%d] = %.*f\n", taulNimi, taulu_i, tarkkuus,
                 taulu[taulu_i]);
    }

    fclose(fyle);

}
