#include <stdio.h>

/* So the width of the list is:
left border + (widest num + 2) + mid border + (widest param + 2)
+ right border.
So, need to find widest num and country first */

int main(int argc, char *argv[])
{
    int biggest_number = argc - 1;
    int bn_width = 1;
    int i = 1;
    int ba_width = 1;
    int list_width = 0;

    int divide = biggest_number / 10;
    while(divide >= 1)
    {
        bn_width += 1;
        divide = divide / 10;
    }
    /* now bn_width has number width. */

    while (i < argc)
    {
        /* Need to find widest argument string */
        int cur_arg_width = 0;
        while(argv[i][cur_arg_width] != '\0') {
            ++cur_arg_width;
        }
        if (cur_arg_width > ba_width)
        {
            ba_width = cur_arg_width;
        }
        ++i;
    }
    /* now ba_width has argument width */
    i = 0;
    list_width = 1 + bn_width + 2 + 1 + ba_width + 2 + 1;

    while(i<list_width)
    {
        printf("#");
        ++i;
    }
    printf("\n");

    i = 1;
    while (i < argc)
    {
        printf("#");
        printf(" %*d ", bn_width, i);
        printf("|");
        printf(" %-*s ", ba_width, argv[i]);
        printf("#\n");

        if(i < biggest_number)
        {
            int sub_i = 0;
            printf("#");
            while(sub_i < (bn_width + 2))
            {
                printf("-");
                ++sub_i;
            }
            printf("+");
            sub_i = 0;
            while(sub_i < (ba_width + 2))
            {
                printf("-");
                ++sub_i;
            }
            printf("#\n");
        }
        ++i;
    }
    i=0;
    while(i<list_width)
    {
        printf("#");
        ++i;
    }
    printf("\n");





    return 0;
}
