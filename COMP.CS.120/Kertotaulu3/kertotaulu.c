#include <stdlib.h>
#include "kertotaulu.h"

Kertotaulu *luoKertotaulu(uint a, uint b, uint c, uint d)
{
    /* This'll dynamically create a Kertotaulu struct, make a 2-dimensional
       array to represent the table, and return a pointer to the struct. */
    int rowCount = d - c + 2;
    int rowLength = b - a + 2;
    int i = 0;

    Kertotaulu *taulu = malloc(sizeof(Kertotaulu));

    uint **kt = malloc(rowCount*sizeof(uint *));

    taulu->a = a;
    taulu->b = b;
    taulu->c = c;
    taulu->d = d;

    /* The first slot of the table, [0][0] is empty. Other rows
       than the first one have the row number in the first slot.
       Thus, a row's length is b - a + 1 + 1, b - a + 2.
       A column's height in turn is d - c + 2.
       The row comes first in the array.
    */


    for(i=0; i<rowCount; ++i)
    {
        /* Now to allocate each row, and calculate values for slots. */
        int j = 0;
        kt[i] = malloc(rowLength*sizeof(uint));

        if(i == 0)
        {
            /* The topmost row with 00 empty, and numbers a through b */
            for(j=0; j<rowLength; ++j)
            {
                if(j == 0)
                {
                    kt[i][j] = 0;
                }
                else
                {
                    kt[i][j] = a + j - 1;
                }
            }
        }
        else
        {
            /* Rows below the topmost. */
            for(j=0; j<rowLength; ++j)
            {

                if(j == 0)
                {
                    kt[i][j] = c + i - 1;
                }
                else
                {
                    kt[i][j] = (c+i-1)*(a+j-1);
                }
            }
        }
    }

    taulu->kertotaulu = kt;

    return taulu;
}

void tuhoaKertotaulu(Kertotaulu *kt)
{

    int rowCount = kt->d - kt->c + 2;

    int i = 0;

    /* First to wipe arrays of the uint**, then the struct itself */
    for(i=0; i<rowCount; ++i)
    {
        uint *row = kt->kertotaulu[i];
        free(row);
    }

    free(kt->kertotaulu);

    free(kt);


}
