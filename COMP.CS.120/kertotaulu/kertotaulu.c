#include <stdio.h>
#include <stdlib.h>

int main()
{

    /* init variables for x and y */
    int x = 0;
    int y = 1;

    /* first column has to be printed outside of loop,
           or rather, in its own loop. */
    /* keep it simple stupid */
    int first_col_x = 1;

    printf("   x");
    for (first_col_x = 1; first_col_x < 16; ++first_col_x) {

        if (first_col_x != 15) {
            printf("%4d", first_col_x);
        }
        else {
            printf("%4d\n", first_col_x);
        }

    }

    /* Rest done in a loop. Have to do it a row at a time,
       so as to use newlines. Y starts 1, first row is 0 */
    for (y = 1; y < 16; ++y) {


        for (x = 0; x < 16; ++x) {
            /* So, if it's the first column where x=0,
               we don't wanna do multiplication */
            if (x == 0) {
                printf("%4d", y);
            } else if (x == 15) {
                printf("%4d\n", x*y);
            }
            else {
                printf("%4d", x*y);
            }
        }
    }





    return 0;
}
