#include <stdio.h>
#include <stdlib.h>
#include "geometria.h"

int main(int argc, char *argv[])
{
    /* extern const long double PII; */
    int i = 1;

    printf("Piin arvo: %20.19Lf\n", PII);

    while ( i < argc) {

        double cur_num = atof(argv[i]);
        double area = ympyranAla(cur_num);
        double volume = pallonTilavuus(cur_num);
        double perimeter = ( 2 * PII * cur_num);

        printf("Säteen %.6f omaavan ympyrän ala ja pallon tilavuus:", cur_num);
        printf(" %.10f ja %.10f\n", area, volume);
        printf("Säteen %.6f omaavan ympyrän piiri on %.10f\n", cur_num, perimeter);

        ++i;
    }

    return 0;
}
