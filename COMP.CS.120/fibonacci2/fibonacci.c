#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fibonacci.h"

char * fib_jono_mj(unsigned int n)
{
    /* Has to do what is specified in the exercise, too long and
       convoluted to explain here */

    int smaller_fib = 0;
    int larger_fib = 1;
    int next_fib = 0;
    int need_realloc = 0;

    int kap = 1;
    int pit = 1;
    unsigned int lukuja_kasitelty = 0;

    const char *vali = ", ";
    char * merkkijono = malloc(kap);



    if(n == 0)
    {
        /* Return string with only endline mark */
        merkkijono[0] = 0;
        pit = 1;
        return merkkijono;
    }
    else
    {
        /* Do whats needed to be done */

        while(lukuja_kasitelty < n)
        {
            /* This here's the main loop, where the next number is
               calculated, necessary memory mumbo jumbo done,
               as well as sprintfing */
            int m = 1;
            int tmp = 0;
            int len = 1;

            if(n == 1)
            {
                next_fib = 0;

            }
            else if (n == 2)
            {
                /* only 0 and 1 to be printed without calculations */
                if(lukuja_kasitelty == 0)
                {
                    next_fib = 0;
                }
                else
                {
                    next_fib = 1;
                }
            }
            else
            {
                if(lukuja_kasitelty == 0)
                {
                    next_fib = 0;
                }
                else if(lukuja_kasitelty == 1)
                {
                    next_fib = 1;
                }
                else
                {
                    next_fib = smaller_fib + larger_fib;
                }

            }
            /* Now the current number to be sprintfed is next_fib */

            /* Here into m is calculated the chars in current number,
               so that we can calculate the exact amount of chars
               in the string for memory purposes
            */

            for(tmp = next_fib; tmp > 9; tmp /= 10)
            {
                len += 1;
            }

            m = len;

            while(pit + m > kap)
            {
                kap = 2*kap;
                need_realloc = 1;
            }
            if(need_realloc == 1)
            {
                merkkijono = realloc(merkkijono, kap);
                need_realloc = 0;
            }

            sprintf(&merkkijono[pit], "%d", next_fib);

            pit = pit + sprintf(&merkkijono[pit-1], "%d", next_fib);

            smaller_fib = larger_fib;
            larger_fib = next_fib;

            lukuja_kasitelty = lukuja_kasitelty + 1;

            if(n > 1 && lukuja_kasitelty != n)
            {

                pit = pit + sprintf(&merkkijono[pit-1], vali);
            }

        }
    }
    /* Now needed memory length needs to be exactly calculated
       and realloced before returning the char array */
    merkkijono = realloc(merkkijono, pit);
    return merkkijono;
}

    /* This is for calculating how many numbers in number
    int tmp = 0;
    int len = 1;
    for(tmp = ; tmp > 9; tmp /= 10)
    {
        len += 1;
    }
    */





