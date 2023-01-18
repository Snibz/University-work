#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pvm.h"

Pvm *kasvataPvm(Pvm *pvm)
{
    /* Moves the date up by one day */

    int is_leap = 0;
    int last_of_month = 0;
    int year = pvm->vuosi;
    int month = pvm->kk;
    int cur_day = pvm->pv;

    if( year % 4 == 0 && year % 100 != 0)
    {
        is_leap = 1;
    }

    if( year % 400 == 0)
    {
        is_leap = 1;
    }

    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
       || month == 10 || month == 12)
    {
        last_of_month = 31;
    }
    if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        last_of_month = 30;
    }

    if(month == 2)
    {
        if(is_leap == 1)
        {
            last_of_month = 29;
        }
        else
        {
            last_of_month = 28;
        }
    }

    if(cur_day < last_of_month)
    {
        /* Don't need to change anything except the day */
        if( strcmp(pvm->vk_pv, "ma")  == 0 )
        {
            strcpy(pvm->vk_pv, "ti");

        }
        else if( strcmp(pvm->vk_pv, "ti")  == 0 )
        {
            strcpy(pvm->vk_pv, "ke");

        }
        else if( strcmp(pvm->vk_pv, "ke")  == 0 )
        {
            strcpy(pvm->vk_pv, "to");

        }
        else if( strcmp(pvm->vk_pv, "to")  == 0 )
        {
            strcpy(pvm->vk_pv, "pe");

        }
        else if( strcmp(pvm->vk_pv, "pe")  == 0 )
        {
            strcpy(pvm->vk_pv, "la");

        }
        else if( strcmp(pvm->vk_pv, "la")  == 0 )
        {
            strcpy(pvm->vk_pv, "su");

        }
        else if( strcmp(pvm->vk_pv, "su")  == 0 )
        {
            strcpy(pvm->vk_pv, "ma");

        }


        cur_day += 1;
        pvm->pv = cur_day;
        return pvm;
    }
    else
    {
        /* It is currently the last of the month.
           Month has to be advanced, maybe year too
        */
        if(month == 12)
        {
            year += 1;
            month = 1;
            pvm->vuosi = year;
            pvm->kk = month;
        }
        else
        {
            month += 1;
            pvm->kk = month;
        }

        if( strcmp(pvm->vk_pv, "ma")  == 0 )
        {
            strcpy(pvm->vk_pv, "ti");

        }
        else if( strcmp(pvm->vk_pv, "ti")  == 0 )
        {
            strcpy(pvm->vk_pv, "ke");

        }
        else if( strcmp(pvm->vk_pv, "ke")  == 0 )
        {
            strcpy(pvm->vk_pv, "to");

        }
        else if( strcmp(pvm->vk_pv, "to")  == 0 )
        {
            strcpy(pvm->vk_pv, "pe");

        }
        else if( strcmp(pvm->vk_pv, "pe")  == 0 )
        {
            strcpy(pvm->vk_pv, "la");

        }
        else if( strcmp(pvm->vk_pv, "la")  == 0 )
        {
            strcpy(pvm->vk_pv, "su");

        }
        else if( strcmp(pvm->vk_pv, "su")  == 0 )
        {
            strcpy(pvm->vk_pv, "ma");

        }

        cur_day = 1;
        pvm->pv = cur_day;
        return pvm;
    }

}

unsigned int pvmEro(const Pvm *a, const Pvm *b)
{
    Pvm *apuptr = malloc(sizeof(Pvm *));
    Pvm apu_pieni;
    Pvm apu_suuri;

    unsigned int ero = 0;

    int equal_days = 0;

    int a_year = a->vuosi;
    int b_year = b->vuosi;
    int a_month = a->kk;
    int b_month = b->kk;
    int a_day = a->pv;
    int b_day = b->pv;

    if(a_year < b_year)
    {
        apu_pieni.pv = a_day;
        apu_pieni.kk = a_month;
        apu_pieni.vuosi = a_year;

        apu_suuri.pv = b_day;
        apu_suuri.kk = b_month;
        apu_suuri.vuosi = b_year;

    }
    else if(b_year < a_year)
    {
        apu_pieni.pv = b_day;
        apu_pieni.kk = b_month;
        apu_pieni.vuosi = b_year;

        apu_suuri.pv = a_day;
        apu_suuri.kk = a_month;
        apu_suuri.vuosi = a_year;
    }
    else
    {
        /* years are equal */


        /* check if months equal */
        if(a_month < b_month)
        {
            apu_pieni.pv = a_day;
            apu_pieni.kk = a_month;
            apu_pieni.vuosi = a_year;

            apu_suuri.pv = b_day;
            apu_suuri.kk = b_month;
            apu_suuri.vuosi = b_year;
        }
        else if(b_month < a_month)
        {
            apu_pieni.pv = b_day;
            apu_pieni.kk = b_month;
            apu_pieni.vuosi = b_year;

            apu_suuri.pv = a_day;
            apu_suuri.kk = a_month;
            apu_suuri.vuosi = a_year;
        }
        else
        {
            /* Years and months are equal, compare days */

            if(a_day < b_day)
            {
                apu_pieni.pv = a_day;
                apu_pieni.kk = a_month;
                apu_pieni.vuosi = a_year;

                apu_suuri.pv = b_day;
                apu_suuri.kk = b_month;
                apu_suuri.vuosi = b_year;
            }
            else if(b_day < a_day)
            {
                apu_pieni.pv = b_day;
                apu_pieni.kk = b_month;
                apu_pieni.vuosi = b_year;

                apu_suuri.pv = a_day;
                apu_suuri.kk = a_month;
                apu_suuri.vuosi = a_year;
            }
            else
            {
                equal_days = 1;
            }
        }

    }
    apuptr->pv = apu_pieni.pv;
    apuptr->kk = apu_pieni.kk;
    apuptr->vuosi = apu_pieni.vuosi;


    /* Now we know which is the 'smaller' date. */
    if(equal_days == 1)
    {
        return ero;
    }


    while(apuptr->pv != apu_suuri.pv || apuptr->kk != apu_suuri.kk ||
       apuptr->vuosi != apu_suuri.vuosi)
    {
        /* If any differs, we advance; if none do, no need */
        apuptr = kasvataPvm(apuptr);
        ero += 1;
    }
    free(apuptr);
    return ero;

}

void tulostaPvm(Pvm *pvm)
{
    printf("%s %d.%d.%d", pvm->vk_pv, pvm->pv, pvm->kk, pvm->vuosi);
}
