#include "muunna.h"




void muunnaTaulu(unsigned int koko, double *taulu, double (*muunnos)(double))
{
    /* Replaces each object of taulu with whatever muunnos returns. */

    unsigned int taulu_index = 0;

    for(taulu_index = 0; taulu_index < koko; ++taulu_index)
    {
        taulu[taulu_index] = muunnos(taulu[taulu_index]);
    }


}
