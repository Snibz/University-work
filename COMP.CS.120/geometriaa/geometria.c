

#include "geometria.h"


const long double PII = 3.1415926535897932385L;

double ympyranAla(double sade)
{
    /* Calculate and return area of circle with radius of sade */

    return (PII*sade*sade);


}

double pallonTilavuus(double sade)
{
    /* Calculate and return volume of ball with radius of sade */
    double volume = (4 * PII * sade*sade*sade) / 3;
    return volume;

}
