#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Valuutta
{
    char *sign;
    double value;
};

typedef struct Valuutta Valuutta;

static int mjKasvavaVrt(const void *a, const void *b)
{
    const Valuutta *x = a;
    const Valuutta *y = b;

    const char *x_sign = (*x).sign;
    const char *y_sign = (*y).sign;

    return strcmp(x_sign, y_sign);
}

int main(int argc, char *argv[])
{

    /* I think doing it by struct makes most sense? idk */
    int size = 1;
    int keep_going = 1;
    int valuutta_count = 0;
    int i = 0;

    Valuutta *array = malloc(size*sizeof(Valuutta));

    while(keep_going == 1)
    {

        char *line = malloc(81*sizeof(char));
        char *command = malloc(81*sizeof(char));
        fgets(line, 81, stdin);
        /* Now line has the line which was entered.
           first word is command. There are either 1 or 3 words,
           if there are 3, second is either the sign or the value
        */
        sscanf(line, "%s", command);

        if(strcmp(command, "kurssi") == 0)
        {
            /* It's kurssi AAA x */
            char *newSign = malloc(4*sizeof(char));
            double newValue = 0;
            int already_existing = 0;
            int existing_i = 0;

            sscanf(line, "%s %s %lf", command, newSign, &newValue);
            /* Gotta see if the array already has a currency with the same sign
            */
            i=0;
            for(i=0; i<valuutta_count; ++i)
            {
                if(strcmp(newSign, array[i].sign) == 0)
                {
                    already_existing = 1;
                    existing_i = i;
                    break;
                }
            }

            if(already_existing == 0)
            {
                Valuutta new_cur;
                new_cur.sign = newSign;
                new_cur.value = newValue;

                if(valuutta_count >= size)
                {
                    size += 1;
                    array = realloc(array, size*sizeof(Valuutta));
                }

                array[valuutta_count] = new_cur;
                valuutta_count += 1;
            }
            else
            {
                array[existing_i].value = newValue;
            }

        }
        else if(strcmp(command, "muunna") == 0)
        {
            /* It's muunna x AAA */
            char *sign = malloc(81*sizeof(char)); /* NOT FREED */
            double amount = 0;
            int val_found = 0;
            int val_i = 0;

            sscanf(line, "%s %lf %s", command, &amount, sign);

            i=0;
            for(i=0; i<valuutta_count; ++i)
            {

                if(strcmp(sign, array[i].sign) == 0)
                {
                    val_found = 1;
                    val_i = i;
                    break;
                }
            }

            if(val_found == 0)
            {
                printf("Valuutan %s kurssia ei ole tiedossa!\n", sign);
            }
            else
            {
                /* 1 euro is valuutta.value of currency sign */
                /* So the value we're looking for is amount / valuutta.value */
                double transformed = amount / array[val_i].value;
                printf("%.*f %s = %.*f EUR\n", 3, amount, sign, 3, transformed);
            }

            free(sign);
        }
        else if(strcmp(command, "kurssit") == 0)
        {
            /* It's kurssit */
            qsort(array, valuutta_count, sizeof(Valuutta), mjKasvavaVrt);
            i=0;
            for(i=0; i<valuutta_count; ++i)
            {
                printf("%s %.*f\n", array[i].sign, 3, array[i].value);
            }

        }
        else if(strcmp(command, "lopeta") == 0)
        {
            /* It's lopeta */
            i=0;
            for(i=0; i<valuutta_count; ++i)
            {
                free(array[i].sign);
            }

            free(array);
            keep_going = 0;
        }

        free(line);
        free(command);

    }


    return 0;
}
