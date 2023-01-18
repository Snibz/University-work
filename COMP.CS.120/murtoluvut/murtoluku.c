#include <stdlib.h>
#include <stdio.h>
#include "murtoluku.h"

int syti(int a, int b)
{
    if(a < 0)
    {
        a = -1 * a;
    }

    if(b < 0)
    {
        b = -1 * b;
    }

    while(a != b)
    {
        if(a>b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return a;
}

Murtoluku supistettuML(int os, int nim)
{
    /* Im just gonna ignore the case where nim is 0, since no guidance was
        provided.
    */
    Murtoluku supistettu;
    int syt = 0;
    int pieni = 0;
    int iso = 0;
    int sup_os = 0;
    int sup_nim = 0;


    if(nim < 0)
    {
        nim = -1 * nim;
        os = -1 * os;
    }

    if(os == 0)
    {
        supistettu.os = os;
        supistettu.nim = nim;
        return supistettu;
    }

    syt = syti(os, nim);
    /* Apparently now syt has the gcd */



    sup_os = os / syt;
    sup_nim = nim / syt;

    supistettu.os = sup_os;
    supistettu.nim = sup_nim;
    return supistettu;

}

Murtoluku lisaaML(Murtoluku a, Murtoluku b)
{

    Murtoluku added;

    int nim3 = 0;
    int os3 = 0;
    int nim_a = a.nim;
    int nim_b = b.nim;
    int os_a = a.os;
    int os_b = b.os;





    nim3 = syti(nim_a, nim_b);

    nim3 = (nim_a * nim_b) / nim3;

    os3 = (os_a) * (nim3 / nim_a) + (os_b) * (nim3 / nim_b);

    added = supistettuML(os3, nim3);
    return added;

}

Murtoluku vahennaML(Murtoluku a, Murtoluku b)
{
    Murtoluku added;
    int syt = 0;
    int nim3 = 0;
    int os3 = 0;
    int nim_a = a.nim;
    int nim_b = b.nim;
    int os_a = a.os;
    int os_b = b.os;


    nim3 = syti(nim_a, nim_b);
    nim3 = (nim_a * nim_b) / nim3;

    os3 = (os_a) * (nim3 / nim_a) - (os_b) * (nim3 / nim_b);

    added = supistettuML(os3, nim3);
    return added;
}

Murtoluku kerroML(Murtoluku a, Murtoluku b)
{
    Murtoluku multiplied;
    int new_os = a.os * b.os;
    int new_nim = a.nim * b.nim;

    multiplied = supistettuML(new_os, new_nim);
    return multiplied;
}

Murtoluku jaaML(Murtoluku a, Murtoluku b)
{
    Murtoluku divided;
    int new_os = a.os * b.nim;
    int new_nim = a.nim * b.os;

    divided = supistettuML(new_os, new_nim);
    return divided;
}

void tulostaML(Murtoluku ml)
{
    if(ml.os == 0)
    {
        printf("0");
    }
    else if(ml.nim == 1)
    {
        printf("%d", ml.os);
    }
    else
    {
        printf("%d/%d", ml.os, ml.nim);
    }
}
