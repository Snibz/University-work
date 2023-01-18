#include <stdio.h>
#include <limits.h>
#include "utf8.h"

void utf8_koodaa(unsigned int merkki, unsigned char utf8[])
{

    unsigned int x = merkki;
    unsigned int size_of_x = CHAR_BIT*sizeof(unsigned int);
    unsigned int x_last_1_bit = 0;
    unsigned int index = 0;
    unsigned int significant_bits = 0;
    unsigned int bytes_needed = 0;
    int test_print_index = 0;

    while (index < size_of_x)
    {
        /* See the index of the last 1 bit of x */
        /* from right to left */
        unsigned int current_bit = ( (x >> index) & 1);
        if (current_bit == 1)
        {
            x_last_1_bit = index;

        }
        ++index;

    }
    significant_bits = x_last_1_bit + 1;

    if (significant_bits < 8)
    {
        bytes_needed = 1;
    }
    else if (significant_bits < 12)
    {
        bytes_needed = 2;
    }
    else if (significant_bits < 17)
    {
        bytes_needed = 3;
    }
    else
    {
        bytes_needed = 4;
    }

    /* Now we know last 1 index, needed bytes */

    index = 0;

    /* setup the array with zeroes, and end mark at last byte */
    while (index <= bytes_needed)
    {
        if (index < bytes_needed)
        {

            utf8[index] = 0;
        }
        else
        {

            utf8[index] = '\0';
        }
        ++index;
    }
    index = 0;

    if (bytes_needed == 1)
    {
        /* THIS IS FUNCTIONAL */
        /* Only byte is 0xxxxxxx */
        utf8[0] = utf8[0] & ~(1 << 7);

        for (index=0; index<7; ++index)
        {
            unsigned int current_bit = ( (x >> index) & 1);

            if (current_bit == 1)
            {
                utf8[0] = utf8[0] | (1 << index);
            }
        }
    }

    if (bytes_needed == 2)
    {
        /* I THINK THIS IS FUNCTIONAL */
        /* bytes are 110xxxxx and 10xxxxxx */
        /* Have own index for x, since it won't be linear
           due to skipping some of the byte prefix indices */
        unsigned int x_index = 0;
        utf8[0] = utf8[0] | (1 << 7);
        utf8[0] = utf8[0] | (1 << 6);
        utf8[0] = utf8[0] & ~(1 << 5);

        utf8[1] = utf8[1] | (1 << 7);
        utf8[1] = utf8[1] & ~(1 << 6);

        for (index=0; index < 6; ++index)
        {
            unsigned int current_bit = ( (x >> x_index) & 1);
            if (current_bit == 1)
            {
                utf8[1] = utf8[1] | (1 << index);
            }
            ++x_index;
        }
        index = 0;
        for (index=0; index<5; ++index)
        {
            unsigned int current_bit = ( (x >> x_index) & 1);
            if (current_bit == 1)
            {
                utf8[0] = utf8[0] | (1 << index);
            }
            ++x_index;
        }


    }

    if (bytes_needed == 3)
    {

        /* 1110xxxx 10xxxxxx 10xxxxxx */
        unsigned int x_index = 0;

        utf8[0] = utf8[0] | (1 << 7);
        utf8[0] = utf8[0] | (1 << 6);
        utf8[0] = utf8[0] | (1 << 5);
        utf8[0] = utf8[0] & ~(1 << 4);

        utf8[1] = utf8[1] | (1 << 7);
        utf8[1] = utf8[1] & ~(1 << 6);

        utf8[2] = utf8[2] | (1 << 7);
        utf8[2] = utf8[2] & ~(1 << 6);

        for (index=0; index < 6; ++index)
        {
            unsigned int current_bit = ( (x >> x_index) & 1);
            if (current_bit == 1)
            {
                utf8[2] = utf8[2] | (1 << index);
            }
            ++x_index;
        }
        index = 0;
        for (index=0; index < 6; ++index)
        {
            unsigned int current_bit = ( (x >> x_index) & 1);
            if (current_bit == 1)
            {
                utf8[1] = utf8[1] | (1 << index);
            }
            ++x_index;
        }
        index = 0;
        for (index=0; index<4; ++index)
        {
            unsigned int current_bit = ( (x >> x_index) & 1);
            if (current_bit == 1)
            {
                utf8[0] = utf8[0] | (1 << index);
            }
            ++x_index;
        }
    }

    if (bytes_needed == 4)
    {

        /* 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx */
        unsigned int x_index = 0;

        utf8[0] = utf8[0] | (1 << 7);
        utf8[0] = utf8[0] | (1 << 6);
        utf8[0] = utf8[0] | (1 << 5);
        utf8[0] = utf8[0] | (1 << 4);
        utf8[0] = utf8[0] & ~(1 << 3);

        utf8[1] = utf8[1] | (1 << 7);
        utf8[1] = utf8[1] & ~(1 << 6);

        utf8[2] = utf8[2] | (1 << 7);
        utf8[2] = utf8[2] & ~(1 << 6);

        utf8[3] = utf8[3] | (1 << 7);
        utf8[3] = utf8[3] & ~(1 << 6);

        for (index=0; index < 6; ++index)
        {
            unsigned int current_bit = ( (x >> x_index) & 1);
            if (current_bit == 1)
            {
                utf8[3] = utf8[3] | (1 << index);
            }
            ++x_index;
        }
        index = 0;
        for (index=0; index < 6; ++index)
        {
            unsigned int current_bit = ( (x >> x_index) & 1);
            if (current_bit == 1)
            {
                utf8[2] = utf8[2] | (1 << index);
            }
            ++x_index;
        }
        index = 0;
        for (index=0; index<6; ++index)
        {
            unsigned int current_bit = ( (x >> x_index) & 1);
            if (current_bit == 1)
            {
                utf8[1] = utf8[1] | (1 << index);
            }
            ++x_index;
        }
        index=0;
        for (index=0; index<3; ++index)
        {
            unsigned int current_bit = ( (x >> x_index) & 1);
            if (current_bit == 1)
            {
                utf8[0] = utf8[0] | (1 << index);
            }
            ++x_index;
        }
    }


    /*
     now to print the utf8
    index = 0;
    while (index < bytes_needed)
    {
        test_print_index = 7;
        while (test_print_index >= 0)
        {
            unsigned int current_bit = ( (utf8[index] >> test_print_index) & 1);
            printf("%u", current_bit);
            --test_print_index;
        }
        ++index;


    }
    printf("\n");
    */
}
