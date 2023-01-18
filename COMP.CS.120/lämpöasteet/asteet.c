#include <stdio.h>
#include <stdlib.h>
#include "asteet.h"

float muunna(Lampotila a, Asteikko b)
{
    /* Returns the temp a as written in the scale b */
    int starting_scale = a.asteikko;
    int ending_scale = b;

    if(starting_scale == 0)
    {
        /* it's celcius */

        if(ending_scale == 0)
        {
            return a.lampotila;
        }

        if(ending_scale == 1)
        {
            /* To fahrenheit */
            float temp = (a.lampotila * 1.8) + 32;
            return temp;
        }

        if(ending_scale == 2)
        {
            /* to Kelvin */
            float temp = a.lampotila + 273.15;
            return temp;
        }


    }
    else if(starting_scale == 1)
    {
        /* It's fahrenheit */

        if(ending_scale == 0)
        {
            float temp = (a.lampotila - 32) / 1.8;
            return temp;
        }

        if(ending_scale == 1)
        {
            return a.lampotila;
        }

        if(ending_scale == 2)
        {
            float temp = ((a.lampotila - 32) / 1.8) + 273.15;
            return temp;
        }
    }
    else
    {
        /* It's kelvin */

        if(ending_scale == 0)
        {
            float temp = a.lampotila - 273.15;
            return temp;
        }

        if(ending_scale == 1)
        {
            float temp = (a.lampotila - 273.15) * 1.8 + 32;
            return temp;
        }

        if(ending_scale == 2)
        {
            return a.lampotila;
        }
    }

}

float erotus(Lampotila a, Lampotila b, Asteikko c)
{
    float a_as_c = muunna(a, c);
    float b_as_c = muunna(b, c);

    float difference = a_as_c - b_as_c;
    return difference;
}
