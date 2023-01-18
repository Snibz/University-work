#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#include <string.h>
#include <signal.h>
#include "signaalit.h"


int main(void)
{
    int size = 1;
    int *array = malloc(size * sizeof(int)); /* NOT FREED */
    int saved = 0;
    char row[100];


    /* Pitää asettaa funktiot käsittelemään signaalit ? */
    signal(SIGFPE, hoidaSIGFPE);
    signal(SIGSEGV, hoidaSIGSEGV);

    while(fgets(row, 100, stdin) != NULL)
    {
        char command[30];
        sscanf(row, "%s", command);

        switch(setjmp(paluuTila))
        {
            case 0:
                /* syöterivin käsittely */
                if(strcmp(command, "lisää") == 0)
                {
                    /* command is lisää */
                    int a = 0;
                    int b = 0;
                    int division = 0;
                    sscanf(row, "%s %d %d", command, &a, &b);

                    while(saved >= size)
                    {
                        size = 2*size;
                    }
                    array = realloc(array, size*sizeof(int));

                    division = a / b;
                    array[saved] = division;
                    saved += 1;

                }
                else if(strcmp(command, "tulosta") == 0)
                {
                    int index = 0;

                    int args = sscanf(row, "%s %u", command, &index);

                    if(args == 1)
                    {
                        int i = 0;
                        while(i < saved)
                        {
                            printf("%d", array[i]);
                            if(i < saved - 1)
                            {
                                printf(" ");
                            }
                            i += 1;
                        }
                        printf("\n");
                    }
                    else if(args == 2)
                    {
                        printf("%d\n", array[index]);
                    }

                }
                break;

            case SIGFPE:
                printf("Aiheutui signaali SIGFPE\n");
                break;

            case SIGSEGV:
                printf("Aiheutui signaali SIGSEGV\n");
                break;

            default:
                /* signaali UNKNOWN*/
                printf("Aiheutui signaali UNKNOWN\n");
                break;
        }

    }
    free(array);
}
