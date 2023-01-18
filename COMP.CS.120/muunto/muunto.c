#include <ctype.h>
#include "muunto.h"


void muunna(char mj[])
{
    /* Makes upper case to lower, lower case to upper
       and sets chars in opposite order;
       Order to REDRo */

    int mj_len = 0;
    int mj_first_i = 0;
    int mj_last_i = 0;

    while(mj[mj_len] != '\0') {
        ++mj_len;
    }
    /* now mj_len should have length of string */
    mj_last_i = mj_len - 1;

    /* Need to do this two at a time i think,
       which means need to do differently on even and odd */
    if (mj_len % 2 != 0)
    {
        /* uneven length, has middle char */
        int mj_mid_i = (mj_len / 2) + 1;

        while (mj_first_i < mj_mid_i)
        {
            char firster_char = mj[mj_first_i];
            char laster_char = mj[mj_last_i];

            if (isupper(firster_char))
            {
                firster_char = tolower(firster_char);
            }
            else
            {
                firster_char = toupper(firster_char);
            }

            if (isupper(laster_char))
            {
                laster_char = tolower(laster_char);
            }
            else
            {
                laster_char = toupper(laster_char);
            }
            /* now cases are reversed */
            mj[mj_first_i] = laster_char;
            mj[mj_last_i] = firster_char;

            ++mj_first_i;
            --mj_last_i;
        }
    }
    else
    {
        /* even number of characters in the string. */
        /* Which means that last index to edit for first half
           is len / 2 - 1 */

        int last_firstend_edit = (mj_len / 2) - 1;
        while (mj_first_i <= last_firstend_edit)
        {
            char firster_char = mj[mj_first_i];
            char laster_char = mj[mj_last_i];

            if (isupper(firster_char))
            {
                firster_char = tolower(firster_char);
            }
            else
            {
                firster_char = toupper(firster_char);
            }

            if (isupper(laster_char))
            {
                laster_char = tolower(laster_char);
            }
            else
            {
                laster_char = toupper(laster_char);
            }
            /* now cases are reversed */
            mj[mj_first_i] = laster_char;
            mj[mj_last_i] = firster_char;

            ++mj_first_i;
            --mj_last_i;
        }

    }


}
