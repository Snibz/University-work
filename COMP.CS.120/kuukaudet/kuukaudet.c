#include <stdio.h>
#include <ctype.h>
#include "kuukaudet.h"

const char *KK_NIMET[KK_LKM] =
{
    "tammikuu", "helmikuu", "maaliskuu", "huhtikuu",
    "toukokuu", "kesäkuu", "heinäkuu", "elokuu",
    "syyskuu", "lokakuu", "marraskuu", "joulukuu"
};

const char KK_PAIVAT[2][KK_LKM] =
{
    {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    },
    {
        31, 29, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    }
};

int karkausvuosi(int vuosiluku)
{
    /* See if the year given as vuosiluku is a leap year.
       Return 1 if it is, 0 if it isn't */
    /* leap year if divisible by 4 but not 100, or divisble by 400 */

    if (vuosiluku % 4 == 0 && vuosiluku % 100 != 0 )
    {
        return 1;
    }
    else if (vuosiluku % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char kkPituus(const char *kkNimi, int vuosiluku)
{
    /* Returns how many days in the month kkNimi in the year vuosikuku */
    int i = 0;
    int keep_going = 1;
    int correct_month_index = 69;

    /* find out if kknimi is valid and which it is */
    while (keep_going > 0)
    {

        for (i=0; i<12; ++i)
        {
            int str_i = 0;
            int is_this_month = 1;
            while (kkNimi[str_i] != '\0')
            {
                if (tolower(kkNimi[str_i]) != tolower(KK_NIMET[i][str_i]) )
                {
                    is_this_month = 0;
                }
                ++str_i;

            }

            if (is_this_month == 1)
            {
                correct_month_index = i;
                keep_going = 0;
            }
        }
        if (i == 12 && correct_month_index == 69)
        {
            keep_going = 0;
        }
    }

    if (correct_month_index == 69)
    {
        return -1;
    }
    else
    {
        /* there is a legit month and we know which it is */
        int is_leap_year = karkausvuosi(vuosiluku);

        if (is_leap_year == 1)
        {
            int days = KK_PAIVAT[1][correct_month_index];
            return days;
        }
        else
        {
            int days = KK_PAIVAT[0][correct_month_index];
            return days;
        }
    }
}
