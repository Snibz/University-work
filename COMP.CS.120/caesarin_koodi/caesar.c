
#include <limits.h>
#include "caesar.h"

void caesarKoodaa(char mj[], char aakkosto[], char korvaavat[])
{

    char encryption[UCHAR_MAX + 1];
    unsigned int i = 0;

    while (i <= UCHAR_MAX)
    {
        encryption[i] = i;
        ++i;
    }
    i= 0;

    while (aakkosto[i] != '\0')
    {
        encryption[aakkosto[i]] = korvaavat[i];
        ++i;
    }
    /* Now for each char (value) in mj, encryption has the char
       that will replace it in mj */
    i = 0;

    while (mj[i] != '\0')
    {
        mj[i] = encryption[mj[i]];
    ++i;
    }
}


