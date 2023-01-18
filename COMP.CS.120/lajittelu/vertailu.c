#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rectangle.h"
#include "vertailu.h"

/* So, if a > b, return positive value
       if a < b, return negative
       if a == b, return 0
*/

int rectAlaVrt(const void *a, const void *b)
{
    Rectangle * const *x = a;
    Rectangle * const *y = b;

    int a_ala = getArea(*x);
    int b_ala = getArea(*y);


    if(a_ala > b_ala)
    {
        return 1;
    }
    else if(b_ala > a_ala)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int rectXyVrt(const void *a, const void *b)
{

    Rectangle * const *x = a;
    Rectangle * const *y = b;

    Point a_og = (*x)->origin;
    Point b_og = (*y)->origin;

    int a_x = a_og.x;
    int b_x = b_og.x;

    int a_y = a_og.y;
    int b_y = b_og.y;

    if(a_x != b_x)
    {
        /* comparison by x values only */
        if(a_x > b_x)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        /* comparison by y */
        if(a_y > b_y)
        {
            return 1;
        }
        else if(b_y > a_y)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

int rectLeveysVrt(const void *a, const void *b)
{
    /* I guess return values invert here, cuz of descending order ? */
    Rectangle * const *x = a;
    Rectangle * const *y = b;

    int a_width = (*x)->width;
    int b_width = (*y)->width;


    if(a_width > b_width)
    {
        return -1;
    }
    else if(b_width > a_width)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int mjPitAakkosVrt(const void *a, const void *b)
{
    /* Primary length, secondary alphabetically.
       descending and ascending, respectively.
    */
    char * const *x = a;
    char * const *y = b;

    size_t a_len = strlen(*x);
    size_t b_len = strlen(*y);

    if(a_len != b_len)
    {
        /* go by length descending */
        if(a_len > b_len)
        {
            return -1;
        }
        else if(b_len > a_len)
        {
            return 1;
        }

    }
    else
    {
        /* go by alphabetic ascending */
        return strcmp(*x, *y);
    }
}
