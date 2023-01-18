#include <stdlib.h>
#include <stdio.h>
#include "kolmijako.h"


IntPari kolmijako(unsigned int n, int t[], int vipu1, int vipu2,
                  int *p1, int *p2)
{
    /* these, or the values of these are returned */
    IntPari palautettava = {0, 0};
    int pienet1 = 0;
    int pienet2 = 0;
    /* for help with vipu and other misc stuff */
    int temp = 0;
    int second_temp = 0;
    int i = 0;

    /* First we see how vipu1 and 2 relate */
    if(t[vipu1] > t[vipu2])
    {
        /* Switch em around */
        temp = vipu1;
        vipu1 = vipu2;
        vipu2 = temp;

    }
    /*
    for(second_temp=0; second_temp < n; ++second_temp)
        {
            printf("%d ", t[second_temp]);
        }
        printf("\n");

    /* Now it's the actual work of the function, to order the objects of t
    in such a way that its smallest < t[vipu1] < smaller < t[vipu2] < rest
    */
    /* t[vipu1] will be on index pienet1 and t[vipu2] on pienet2. Both indices
    are equal to the number of objects that are smaller than themselves.
    */
    temp = 0;

    for(i=0; i<n; ++i)
    {
        /* First place everything smaller than t[vipu1] 'below' pienet1 */
        if(t[i] < t[vipu1])
        {
            temp = t[i];

            t[i] = t[pienet1];
            t[pienet1] = temp;

            if(vipu1 == pienet1)
            {
                vipu1 = i;
            }
            if(vipu2 == pienet1)
            {
                vipu2 = i;
            }

            pienet1 += 1;
        }
/*
        for(second_temp=0; second_temp < n; ++second_temp)
        {
            printf("%d ", t[second_temp]);
        }
        printf("\n");
        */
    }


    temp = t[vipu1];
    t[vipu1] = t[pienet1];
    t[pienet1] = temp;
   /* printf("temp: %d\n", temp);*/

    if(pienet1 == vipu2)
    {
        vipu2 = vipu1;
    }

   /* printf("second loop:\n");
    printf("t[vipu2]: %d\n", t[vipu2]);
    for(second_temp=0; second_temp < n; ++second_temp)
        {
            printf("%d ", t[second_temp]);
        }
        printf("\n");
*/
    pienet2 = pienet1 + 1;
    i = pienet2;
    for(i=pienet2; i<n; ++i)
    {

        if(t[i] < t[vipu2])
        {
            temp = t[i];

            t[i] = t[pienet2];
            t[pienet2] = temp;

            if(pienet2 == vipu2)
            {
                /*printf("pienet2: %d and vipu2: %d equal - assigning vipu2 as temp: %d\n", pienet2, vipu2, temp);*/
                vipu2 = i;
            }

            pienet2 += 1;

        }

    }

    temp = t[vipu2];

    t[vipu2] = t[pienet2];
    t[pienet2] = temp;


    palautettava.x = pienet1;
    palautettava.y = pienet2;

    *p1 = pienet1;
    *p2 = pienet2;

    return palautettava;
}
