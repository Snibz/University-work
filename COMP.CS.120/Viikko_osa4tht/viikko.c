#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "viikko.h"


void viikko(int pv, int kk, int vuosi)
{

    int i = 0;
    time_t aika = time(NULL);
    struct tm *aikastruct = gmtime(&aika);

    aikastruct->tm_mday = pv;
    aikastruct->tm_mon = kk - 1;
    aikastruct->tm_year = vuosi - 1900;
    aika = mktime(aikastruct);

    /* First set the aikastruct to point to the monday of the week */

    while( aikastruct->tm_wday != 1)
    {
        aikastruct->tm_mday -= 1;
        aika = mktime(aikastruct);

    }
    /* Now aikastruct should have the monday */

    i = 0;
    for(i=0; i < 7; ++i)
    {
        char mj[50];
        strftime(mj, 50, "%A %d. %B %Y", aikastruct);

        printf("%s\n", mj);

        aikastruct->tm_mday += 1;
        aika = mktime(aikastruct);

    }

}
