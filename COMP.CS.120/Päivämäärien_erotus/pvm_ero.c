#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "pvm_ero.h"


void pvm_ero(const char *pvm1, const char *pvm2)
{

    int either_day_invalid = 0;
    double difference = 0;
    int difference_in_days = 0;
    int pvm1_day = 0;
    int pvm1_month = 0;
    int pvm1_year = 0;

    int pvm2_day = 0;
    int pvm2_month = 0;
    int pvm2_year = 0;

    int temp_day = 0;
    int temp_month = 0;
    int temp_year = 0;

    /*trying malloc here due to crashing */
    struct tm *smaller = malloc(sizeof(struct tm));
    struct tm *larger = malloc(sizeof(struct tm));

    time_t smaller_tt;
    time_t larger_tt;

    char date1_line[50];
    char date2_line[50];

    setlocale(LC_TIME, "fi_FI.utf8");

    smaller->tm_sec = 0;
    smaller->tm_min = 0;
    smaller->tm_hour = 0;
    smaller->tm_mday = 0;
    smaller->tm_mon = 0;
    smaller->tm_year = 0;
    smaller->tm_wday = 0;
    smaller->tm_yday = 0;
    smaller->tm_isdst = 0;

    larger->tm_sec = 0;
    larger->tm_min = 0;
    larger->tm_hour = 0;
    larger->tm_mday = 0;
    larger->tm_mon = 0;
    larger->tm_year = 0;
    larger->tm_wday = 0;
    larger->tm_yday = 0;
    larger->tm_isdst = 0;

    sscanf(pvm1, "%2d.%2d.%4d", &pvm1_day, &pvm1_month, &pvm1_year);
    sscanf(pvm2, "%2d.%2d.%4d", &pvm2_day, &pvm2_month, &pvm2_year);

    pvm1_month -= 1;
    pvm1_year = pvm1_year - 1900;
    pvm2_month -= 1;
    pvm2_year = pvm2_year - 1900;


    if(pvm1_year == pvm2_year)
    {
        /* Setup years, size not yet established */
        smaller->tm_year = pvm1_year;
        larger->tm_year = pvm2_year;

        if(pvm1_month == pvm2_month)
        {
            smaller->tm_mon = pvm1_month;
            larger->tm_mon = pvm2_month;

            if(pvm1_day == pvm2_day)
            {
                smaller->tm_mday = pvm1_day;
                larger->tm_mday = pvm2_day;
            }
            else
            {
                /* equal months, days difer */
                if(pvm1_day < pvm2_day)
                {
                    smaller->tm_mday = pvm1_day;
                    larger->tm_mday = pvm2_day;
                }
                else
                {
                    smaller->tm_mday = pvm2_day;
                    larger->tm_mday = pvm1_day;
                }
            }
        }
        else
        {
            if(pvm1_month < pvm2_month)
            {
                smaller->tm_mon = pvm1_month;
                smaller->tm_mday = pvm1_day;
                larger->tm_mon = pvm2_month;
                larger->tm_mday = pvm2_day;
            }
            else
            {
                smaller->tm_mon = pvm2_month;
                smaller->tm_mday = pvm2_day;
                larger->tm_mon = pvm1_month;
                larger->tm_mday = pvm1_day;
            }
        }
    }
    else
    {
        /* years differ */
        if(pvm1_year < pvm2_year)
        {
            smaller->tm_year = pvm1_year;
            larger->tm_year = pvm2_year;
            smaller->tm_mon = pvm1_month;
            smaller->tm_mday = pvm1_day;
            larger->tm_mon = pvm2_month;
            larger->tm_mday = pvm2_day;
        }
        else
        {
            smaller->tm_year = pvm2_year; /* seems to crash here */
            larger->tm_year = pvm1_year;
            smaller->tm_mon = pvm2_month;
            smaller->tm_mday = pvm2_day;
            larger->tm_mon = pvm1_month;
            larger->tm_mday = pvm1_day;
        }
    }

    /* Now to check validity of given dates */
    temp_day = smaller->tm_mday;
    temp_month = smaller->tm_mon;
    temp_year = smaller->tm_year;

    smaller->tm_isdst = 0;
    mktime(smaller);

    if(smaller->tm_mday != temp_day || smaller->tm_mon != temp_month
       || smaller->tm_year != temp_year)
    {
        either_day_invalid = 1;
    }

    temp_day = larger->tm_mday;
    temp_month = larger->tm_mon;
    temp_year = larger->tm_year;

    larger->tm_isdst = 0;
    mktime(larger);

    if(larger->tm_mday != temp_day || larger->tm_mon != temp_month
       || larger->tm_year != temp_year)
    {
        either_day_invalid = 1;
    }

    if(either_day_invalid == 1)
    {
        fprintf(stderr, "Parametri \"%s\" tai \"%s\" on laiton!\n", pvm1, pvm2);
        return;
    }

    /* If code continues here, dates are valid */
    smaller->tm_isdst = 0;
    larger->tm_isdst = 0;
    smaller_tt = mktime(smaller);
    larger_tt = mktime(larger);

    difference = difftime(larger_tt, smaller_tt);
    difference_in_days = (difference + 86400) / 86400;

    strftime(date1_line, 50, "%A %d.%m.%Y", smaller);
    strftime(date2_line, 50, "%A %d.%m.%Y", larger);

    printf("%s --> %s: yhteensä %d päivää\n", date1_line, date2_line,
            difference_in_days);

    free(smaller);
    free(larger);
    return;

}
