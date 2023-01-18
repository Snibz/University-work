#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    int i = 1;


    for(i=1; i<argc; ++i)
    {
        /*
        int signedchar = 0;
        int unsignedchar = 0;
        int shortint = 0;
        int unsignedshortint = 0;
        int integer = 0;
        */


        int num = atoi(argv[i]);
        printf("%d: ", num);

        if(SCHAR_MIN <= num && SCHAR_MAX >= num)
        {

            printf("signed char, ");
        }

        if(0 <= num && UCHAR_MAX >= num)
        {

            printf("unsigned char, ");
        }

        if(SHRT_MIN <= num && SHRT_MAX >= num)
        {

            printf("short int, ");
        }

        if(0 <= num && USHRT_MAX >= num)
        {

            printf("unsigned short int, ");
        }

        if(INT_MIN <= num && INT_MAX >= num)
        {

            printf("int\n");
        }

    }

    return 0;
}
