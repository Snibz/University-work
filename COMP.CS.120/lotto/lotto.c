#include <stdlib.h>
#include <stdio.h>



int main(int argc, char *argv[]) {
    /* first 7 additional args are winning numbers, last 7
    are chosen numbers.
    Need to check chosen numbers to winning numbers in
    their given order. */


    int first_chosen_index = 8;

    int winning_array[7];
    int chosen_array[7];

    int i = 0;

    int matches_array[7];
    int matches = 0;
    int chosen_index = 0;

    for (i=0; i<first_chosen_index-1; ++i) {
        winning_array[i] = atoi(argv[i+1]);
    }

    for (i=0; i<7; ++i) {
        chosen_array[i] = atoi(argv[i+8]);
    }

    i = 0;
    printf("Voittorivi:");
    while (i < 7) {

        if (i != 6) {
            printf(" %d", winning_array[i]);
        } else {
            printf(" %d\n", winning_array[i]);
        }
        i += 1;
    }

    i = 0;
    printf("Lottorivi:");
    while (i < 7) {

        if (i != 6) {
            printf(" %d", chosen_array[i]);
        } else {
            printf(" %d\n", chosen_array[i]);
        }
        i += 1;
    }
    /*
    int matches_array[7];
    int matches = 0;
    int chosen_index = 0;
    */
    while (chosen_index < 7) {
        int winning_index = 0;
        int chosen_number = chosen_array[chosen_index];

        for (winning_index = 0; winning_index < 7; ++winning_index) {

            if (chosen_number == winning_array[winning_index]) {
                matches_array[matches] = chosen_number;
                matches += 1;
            }
        }
        chosen_index += 1;
    }

    if (matches == 0) {
        printf("Ei yhtään oikein!\n");
    } else {
        printf("%d oikein:", matches);
        i = 0;
        while (i < matches) {
            printf(" %d", matches_array[i]);
            i += 1;
        }
        printf("\n");
    }

return 0;
}
