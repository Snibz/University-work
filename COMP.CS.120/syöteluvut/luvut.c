#include <stdio.h>
#include <stdlib.h>



static int double_comp(const void *a, const void *b)
{
    const double *x = a;
    const double *y = b;

    if(*x > *y)
    {
        return 1;
    }
    else if(*x < *y)
    {
        return -1;
    }
    else
    {
        return 0;
    }

}

int main(int argc, char *argv[])
{

    size_t koko = 2;
    double sum = 0;
    double average = 0;
    int print_i = 0;
    int doubles_stored = 0;
    double *array = malloc(koko*sizeof(double));
    int keep_going = 1;

    while(keep_going == 1)
    {
        double number = 0;
        int scanf_return = scanf("%lf", &number);

        if(scanf_return == 1)
        {
            /* A double was entered, need to see if array has space,
               +1 for the ending char */
            if(doubles_stored + 1 >= koko)
            {
                /*printf("tarvittu koko: %d , nyk koko: %d\n", doubles_stored + 1, koko);*/
                /* need more space */
                koko = 2*koko;
                array = realloc(array, koko*sizeof(double));
            }
            /* now array should have enough memory regardless */
            array[doubles_stored] = number;
            doubles_stored += 1;

        }
        else
        {
            /* 0 was returned, so no more numbers will be read */
            koko = doubles_stored;
            array = realloc(array, koko*sizeof(double));
            keep_going = 0;
        }
    }

    /* Now array needs to be sorted before any printings take place */
    qsort(array, doubles_stored, sizeof(double), double_comp);
    /* guess it's sorted now */


    printf("Luettiin %d lukua: ", doubles_stored);
    for(print_i = 0; print_i < doubles_stored; ++print_i)
    {
        printf("%.3f", array[print_i]);
        sum += array[print_i];

        if(print_i != doubles_stored - 1)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }

    printf("Summa: %.3f\n", sum);
    average = sum / doubles_stored;
    printf("Keskiarvo: %.3f\n", average);

    free(array);

    return 0;
}
