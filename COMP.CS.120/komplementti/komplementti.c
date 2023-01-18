#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[])
{
    int numbers_in_arg = 0;
    int largest_exponent = 0;
    int i = 0;
    int base10_num = 0;

    while (argv[1][numbers_in_arg] != '\0')
    {
        ++numbers_in_arg;
    }

    largest_exponent = numbers_in_arg - 1;


    while (i < numbers_in_arg)
    {


        if (i == 0)
        {
            /* this number being 1 means its negative */
            if (argv[1][i] == '1')
            {
                base10_num += -1 * pow(2, largest_exponent);
            }

        }
        else
        {
            if (argv[1][i] == '1')
            {
                base10_num += pow(2, largest_exponent);
            }
        }
        ++i;
        --largest_exponent;
    }

    printf("%d\n", base10_num);






    return 0;
}
