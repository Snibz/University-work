#include <stdio.h>
#include <stdlib.h>

#include "genhaku.h"


size_t etsi(void *mista, size_t n, void *mita, size_t m, size_t koko)
{
    char *a = mista;
    char *b = mita;


    int mista_i = 0;
    int mita_i = 0;

    size_t mista_equal_beginning_i = 0;
    int current_equal_counter = 0;
    int mista_obj_handled = 0;

    while(mista_obj_handled < n)
    {

        if(a[mista_i*koko] == b[mita_i*koko] )
        {
            /* Go through all of the bytes relevant to the object */
            int k = 0;
            int is_equal = 1;

            while(k <= koko - 1 && is_equal == 1)
            {
                if(a[mista_i*koko + k] == b[mita_i*koko + k])
                {
                    k += 1;
                    continue;
                }
                else
                {
                    k += 1;
                    is_equal = 0;
                }
            }
            /* Now is_equal should be 1 if theyre same, 0 if not */
            if(is_equal == 1)
            {

                if(current_equal_counter == 0)
                {
                    mista_equal_beginning_i = mista_i;
                    current_equal_counter += 1;
                }
                else
                {
                    current_equal_counter += 1;
                }
                mita_i += 1;

            }
            else
            {
                current_equal_counter = 0;
                mita_i = 0;
                mista_equal_beginning_i = 0;
            }

        }
        else
        {
            current_equal_counter = 0;
                mita_i = 0;
                mista_equal_beginning_i = 0;
        }
        mista_obj_handled += 1;
        mista_i += 1;

        if(current_equal_counter == m)
        {
            return mista_equal_beginning_i;
        }
    }
    return n;
}
