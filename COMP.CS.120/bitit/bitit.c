#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bitit.h"

void scharBitit(signed char x)
{
    int amount_of_bits = CHAR_BIT;
    int i = amount_of_bits - 1;
    int zero_count = 0;
    int one_count = 0;

    printf("%d\n", x);

    while (i >= 0)
    {
        int current = 69;

        current = ( (x >> i) & 1 );

        if (current == 0)
        {
            printf("0");
            ++zero_count;
        }
        else if (current == 1)
        {
            printf("1");
            ++one_count;
        }
        --i;

    }
    printf("\n");
    printf("%d\n", zero_count);
    printf("%d\n", one_count);

}

void shortBitit(short int x)
{
    int amount_of_bits = sizeof(short int)*CHAR_BIT;
    int i = amount_of_bits - 1;
    int zero_count = 0;
    int one_count = 0;

    printf("%d\n", x);

    while (i >= 0)
    {
        int current = 69;

        current = ( (x >> i) & 1 );

        if (current == 0)
        {
            printf("0");
            ++zero_count;
        }
        else if (current == 1)
        {
            printf("1");
            ++one_count;
        }
        --i;

    }
    printf("\n");
    printf("%d\n", zero_count);
    printf("%d\n", one_count);

}

void intBitit(int x)
{
    int amount_of_bits = sizeof(int)*CHAR_BIT;
    int i = amount_of_bits - 1;
    int zero_count = 0;
    int one_count = 0;

    printf("%d\n", x);

    while (i >= 0)
    {
        int current = 69;

        current = ( (x >> i) & 1 );

        if (current == 0)
        {
            printf("0");
            ++zero_count;
        }
        else if (current == 1)
        {
            printf("1");
            ++one_count;
        }
        --i;

    }
    printf("\n");
    printf("%d\n", zero_count);
    printf("%d\n", one_count);

}

void longBitit(long int x)
{
    int amount_of_bits = sizeof(long int)*CHAR_BIT;
    int i = amount_of_bits - 1;
    int zero_count = 0;
    int one_count = 0;

    printf("%ld\n", x);

    while (i >= 0)
    {
        int current = 69;

        current = ( (x >> i) & 1 );

        if (current == 0)
        {
            printf("0");
            ++zero_count;
        }
        else if (current == 1)
        {
            printf("1");
            ++one_count;
        }
        --i;

    }
    printf("\n");
    printf("%d\n", zero_count);
    printf("%d\n", one_count);
}
