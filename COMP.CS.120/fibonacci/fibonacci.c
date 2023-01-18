#include <stdlib.h>
#include "fibonacci.h"

unsigned int * fib_jono(unsigned int n)
{
    /* Create a dynamically allocated array with n elements.
       The elements are the first n Fibonacci numbers, in such order
       that element Fi is saved to index i. */

    unsigned int * jono = calloc(n, sizeof(unsigned int));

    /* index 0 on 0, index 1 on 1. */
    if (n >= 1)
    {
        jono[0] = 0;
    }
    if (n >= 2)
    {
        jono[1] = 1;
    }

    if (n > 2)
    {
        int i = 2;

        while (i < n)
        {
            jono[i] = ( jono[i-1] + jono[i-2] );
            ++i;
        }
    }

    return jono;

}
