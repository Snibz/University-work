#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(void)
{
    char viikonpaiva[15];
    char paivamaara[15];
    char kellonaika[15];

    time_t aika = time(NULL);
    struct tm *aikastruct = localtime(&aika);
    int vkpv = aikastruct->tm_wday;

    if(vkpv == 0)
    {
        strcpy(viikonpaiva, "Sunnuntai");
    }
    else if(vkpv == 1)
    {
        strcpy(viikonpaiva, "Maanantai");
    }
    else if(vkpv == 2)
    {
        strcpy(viikonpaiva, "Tiistai");
    }
    else if(vkpv == 3)
    {
        strcpy(viikonpaiva, "Keskiviikko");
    }
    else if(vkpv == 4)
    {
        strcpy(viikonpaiva, "Torstai");
    }
    else if(vkpv == 5)
    {
        strcpy(viikonpaiva, "Perjantai");
    }
    else if(vkpv == 6)
    {
        strcpy(viikonpaiva, "Lauantai");
    }

    strftime(paivamaara, 15*sizeof(char), "%d.%m.%Y", aikastruct);
    strftime(kellonaika, 15*sizeof(char), "%H:%M", aikastruct);


    printf("%s %s klo %s\n", viikonpaiva, paivamaara, kellonaika);
    return 0;

}
