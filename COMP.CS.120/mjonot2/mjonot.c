#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mjonot.h"

char ** jarjesta_mjt(char **mjt, size_t lkm,
                      int (*vrt)(const char*, const char*))
{



    int i = 0;
    int max_i = lkm - 1;
    int comparison_i = 0;
    char **kopio = malloc(lkm*sizeof(char *));

    while (i <= max_i)
    {
        int sub_i = 0;
        /*int comparison_i = i - 1;*/
        size_t length = strlen(mjt[i]);

        char *kopio_sana = malloc(length + 1);
        strcpy(kopio_sana, mjt[i]);

        kopio[i] = kopio_sana;

        /* while(comparison_i > 0)
        {
             Compare current string with one lower in the char**
            int vertailu = vrt(kopio[i], kopio[comparison_i]);
            if(vertailu != 0)
            {
                 kopio[i] should come before kopio[comparison]
                char *temp_kopio = kopio[comparison_i];
                kopio[comparison_i] = kopio[i];
                kopio[i] = temp_kopio;
            }

            comparison_i -= 1;
        }
        */




        ++i;
    }

    /* Now starting from the top compare current word with each lower on the
       array. */

    i = max_i;
    while(i > 0)
    {

        comparison_i = i - 1;

        while(comparison_i > -1)
        {

            int vertailu = vrt(kopio[i], kopio[comparison_i]);

            if(vertailu != 0)
            {

                char *temp_kopio = kopio[comparison_i];
                kopio[comparison_i] = kopio[i];
                kopio[i] = temp_kopio;
            }

            comparison_i -= 1;
        }

        i -= 1;
    }





    return kopio;

}

