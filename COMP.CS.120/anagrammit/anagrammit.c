#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "anagrammit.h"



int anagrammeja(char mj1[], char mj2[])
{

    /* Well they're not anagrams if their length differs, check that first */

    if(strlen(mj1) != strlen(mj2))
    {
        /* Not anagrams */
        return 0;
    }
    else
    {
        /* Make an array for counts of each character for use in determining
           if theyre anagrams */
        int is_anagram = 1;
        int i = 0;
        int count[UCHAR_MAX + 1];

        for(i=0; i <= UCHAR_MAX; ++i)
        {
            count[i] = 0;
        }
        /* Now the array has a 0 on every slot, and if the strings are anagrams
           then in the end it'll also have all zeroes. */
        i=0;
        for(i=0; i < strlen(mj1); ++i)
        {

        char current = mj1[i];
        int cur_num = count[current];
        cur_num += 1;
        count[current] = cur_num;

        }

        i=0;
        for(i=0; i < strlen(mj1); ++i)
        {

            char current = mj2[i];
            int cur_num = count[current];
            cur_num -= 1;
            count[current] = cur_num;
        }

        /* I guess now check whole array, if even a single object is not 0,
           then no anagram. Else is.
        */
        i=0;
        for(i=0; i <= UCHAR_MAX; ++i)
        {
            if(count[i] != 0)
            {
                is_anagram = 0;
            }
        }


        return is_anagram;
    }


}
