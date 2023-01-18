#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{

    int i = 9;
    int arvo_eksp = 1;
    double arvo_osa = 0.0;
    int eksponentti = 0;
    int eksp_eksp = 7;
    int etumerkki = 0;
    double liukuluku = 0.0;

    while ( i < 32)
    {
        if (argv[1][i] == '1')
        {
            arvo_osa += ( 1.0 / pow(2, arvo_eksp));
        }
        ++i;
        ++arvo_eksp;
    }
    arvo_osa += 1.0;

    printf("%.15f\n", arvo_osa);

    i = 1;
    while (i < 9)
    {
        if (argv[1][i] == '1')
        {
            eksponentti += pow(2, eksp_eksp);
        }
        ++i;
        --eksp_eksp;
    }
    eksponentti = eksponentti - 127;

    printf("%d\n", eksponentti);

    i = 0;
    if (argv[1][i] == '1')
    {
        etumerkki = 1;
        printf("-\n");
    }
    else
    {
        etumerkki = 0;
        printf("+\n");
    }

    liukuluku = arvo_osa * pow(2, eksponentti);

    if (etumerkki == 1)
    {
        liukuluku = -1*liukuluku;
    }
    printf("%.15f\n", liukuluku);




    return 0;
}
