#include <stdio.h>
#include <stdlib.h>
#include "vaihto.h"

void vaihda(int *a, int *b)
{
    int apu = *a;

    *a = *b;
    *b = apu;
}

void jarjesta(int* a, int* b, int* c)
{
    int pienin;
    int keski;
    int suurin;
    int a_used = 0;
    int b_used = 0;
    int c_used = 0;

    if (*a <= *b && *a <= *c)
    {
        pienin = *a;
        a_used = 1;
    }
    else if (*b <= *a && *b <= *c)
    {
        pienin = *b;
        b_used = 1;
    }
    else if (*c <= *a && *c <= *b)
    {
        pienin = *c;
        c_used = 1;
    }

    if (*a >= *b && *a >= *c)
    {
        suurin = *a;
        a_used = 1;
    }
    else if (*b >= *a && *b >= *c)
    {
        suurin = *b;
        b_used = 1;
    }
    else if (*c >= *a && *c >= *b)
    {
        suurin = *c;
        c_used = 1;
    }

    if (a_used != 1)
    {
        keski = *a;
    }
    else if (b_used != 1)
    {
        keski = *b;
    }
    else if (c_used != 1)
    {
        keski = *c;
    }

    *a = pienin;
    *b = keski;
    *c = suurin;

}
