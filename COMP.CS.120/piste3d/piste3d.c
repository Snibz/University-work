#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "piste3d.h"

double etaisyys(Piste3D first, Piste3D second)
{
    double distance = sqrt( pow((first.x - second.x), 2) +
                           pow((first.y - second.y), 2) +
                           pow((first.z - second.z), 2) );

    return distance;
}

void tulosta(Piste3D p, int tarkkuus)
{
    printf("(%.*f, %.*f, %.*f)", tarkkuus, p.x, tarkkuus, p.y, tarkkuus, p.z);

}
