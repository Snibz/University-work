#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "bitit.h"


void kaannaScharBitit(signed char *x)
{
    /* Trying it again */
    /* this was a real pain in the ass */

    int bits_in_byte = CHAR_BIT;
    int i = 0;
    int largest_i = bits_in_byte - 1;
    int alt_i = largest_i - i;
    /* char apulista[UCHAR_MAX]; */


    while (i < alt_i)
    {
        int current_rightside = 69;
        int current_leftside = 96;
        alt_i = largest_i - i;

        current_rightside = ( (*x >> i) & 1);
        current_leftside = ( (*x >> (alt_i) ) & 1);

        if (current_rightside == 1)
        {
            /* make cur left 1 */
            *x = *x | (1 << (alt_i));
        }
        if (current_rightside == 0)
        {
            *x = *x & ~(1 << (alt_i));
        }

        if (current_leftside == 1)
        {
            *x = *x | (1 << i);

        }
        if (current_leftside == 0)
        {
            *x = *x & ~(1 << i);

        }

        ++i;

    }

}


void kaannaShortBitit(short *x)
{

    int bits_in_byte = sizeof(short int)*CHAR_BIT;
    int i = 0;
    int largest_i = bits_in_byte - 1;
    int alt_i = largest_i - i;
    /* char apulista[UCHAR_MAX]; */


    while (i < alt_i)
    {
        int current_rightside = 69;
        int current_leftside = 96;
        alt_i = largest_i - i;

        current_rightside = ( (*x >> i) & 1);
        current_leftside = ( (*x >> (alt_i) ) & 1);

        if (current_rightside == 1)
        {
            /* make cur left 1 */
            *x = *x | (1 << (alt_i));
        }
        if (current_rightside == 0)
        {
            *x = *x & ~(1 << (alt_i));
        }

        if (current_leftside == 1)
        {
            *x = *x | (1 << i);

        }
        if (current_leftside == 0)
        {
            *x = *x & ~(1 << i);

        }

        ++i;

    }


}

void kaannaIntBitit(int *x)
{

    int bits_in_byte = sizeof(int)*CHAR_BIT;
        int i = 0;
    int largest_i = bits_in_byte - 1;
    int alt_i = largest_i - i;
    /* char apulista[UCHAR_MAX]; */


    while (i < alt_i)
    {
        int current_rightside = 69;
        int current_leftside = 96;
        alt_i = largest_i - i;

        current_rightside = ( (*x >> i) & 1);
        current_leftside = ( (*x >> (alt_i) ) & 1);

        if (current_rightside == 1)
        {
            /* make cur left 1 */
            *x = *x | (1 << (alt_i));
        }
        if (current_rightside == 0)
        {
            *x = *x & ~(1 << (alt_i));
        }

        if (current_leftside == 1)
        {
            *x = *x | (1 << i);

        }
        if (current_leftside == 0)
        {
            *x = *x & ~(1 << i);

        }

        ++i;

    }



}

void kaannaLongBitit(long *x)
{

    long int bits_in_byte = sizeof(long int)*CHAR_BIT;
        int i = 0;
    long int largest_i = bits_in_byte - 1;
    long int alt_i = largest_i - i;
    /* char apulista[UCHAR_MAX]; */


    while (i < alt_i)
    {
        long int current_rightside = 69;
        long int current_leftside = 96;
        alt_i = largest_i - i;

        current_rightside = ( (*x >> i) & 1);
        current_leftside = ( (*x >> (alt_i) ) & 1);

        if (current_rightside == 1)
        {
            /* make cur left 1 */
            *x = *x | (1L << (alt_i));
        }
        if (current_rightside == 0)
        {
            *x = *x & ~(1L << (alt_i));
        }

        if (current_leftside == 1)
        {
            *x = *x | (1L << i);

        }
        if (current_leftside == 0)
        {
            *x = *x & ~(1L << i);

        }

        ++i;

    }

}

