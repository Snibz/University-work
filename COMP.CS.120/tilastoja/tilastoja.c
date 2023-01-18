#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

    int float_count = argc - 1;
    int smallest_index = 1;
    int largest_index = float_count;
    int current_index = smallest_index;


    double smallest = 0.0;
    double largest = 0.0;


    int uniques = 0;
    int most_appearance_count = 0;

    int mac_printed = 0;


    int i = 0;
    for (i = 0;  i < float_count; ++i) {
        double cur_num = atof(argv[i+1]);

        if (i == 0) {
            smallest = cur_num;
            largest = cur_num;
        } else {
            if (cur_num < smallest) {
                smallest = cur_num;
            }
            if (cur_num > largest) {
                largest = cur_num;
            }
        }
    }

    printf("Pienin: %f\n", smallest);
    printf("Suurin: %f\n", largest);



    for (current_index = smallest_index;
        current_index <= largest_index; ++current_index) {

        double current_number = atof(argv[current_index]);
        int number_of_equalities = 0;
        int number_appearances = number_of_equalities + 1;

        int comp_index = smallest_index;
        for (comp_index = smallest_index;
            comp_index <= largest_index; ++comp_index) {

            double comp_number = atof(argv[comp_index]);

            if (comp_index == current_index) {
                continue;
            } else {

                if (comp_number == current_number) {
                    number_of_equalities += 1;
                }
            }
        }

        if (number_of_equalities == 0) {

            if (uniques == 0) {
                printf("Ainutlaatuiset:");
            }
            printf(" %f", current_number);
            uniques += 1;
        }
        number_appearances = number_of_equalities + 1;
        if (number_appearances > most_appearance_count) {
            most_appearance_count = number_appearances;
        }
    }
    if (uniques > 0) {
        printf("\n");
    }
    /* Now, I only need to do a one-way comparison
    here, because duplicates are this way impossible.
    We'll compare counts for each number to the variable
    most_appearance_count. */

    current_index = smallest_index;
    for (current_index = smallest_index;
    current_index <= largest_index; ++current_index) {

        double current_number = atof(argv[current_index]);
        int current_number_instances = 1;

        int comp_index = current_index;
        for (comp_index = current_index;
            comp_index <= largest_index; ++comp_index) {
            double comp_number = atof(argv[comp_index]);
            if (comp_index == current_index) {
                continue;
            } else {

                if (comp_number == current_number) {
                    current_number_instances += 1;
                }
            }
        }

        if (current_number_instances == most_appearance_count
            && most_appearance_count > 1 ) {

            if (mac_printed == 0) {
                printf("Useimmiten esiintyneet (%d kertaa):", current_number_instances);
                mac_printed += 1;
            }
            printf(" %f", current_number);
        }
    }
    if (mac_printed > 0) {
        printf("\n");
    }





    /*
    for (i=0; i < float_count; ++i) {
        double cur_num = atof(argv[i+1]);
        int cur_num_count = 1;
        int following_index = i+2;



        for (following_index = i+2;
            following_index < float_count; ++following_index) {
            if (cur_num == atof(argv[following_index])) {
                cur_num_count += 1;
            }
        }

        if (cur_num_count == 1) {

            if (uniques == 0) {
                printf("Ainutlaatuiset:");
            }
            printf(" %f", cur_num);
            uniques += 1;
         }

         if (cur_num_count > most_appearance_count) {
            most_appearance_count = cur_num_count;
         }


    }
    if (uniques > 0) {
        printf("\n");
    }

    if (most_appearance_count > 1) {

        for (i = 0; i < float_count; ++i) {
            double cur_num = atof(argv[i+1]);
            int cur_num_count = 1;

            int following_index = i+2;



            for (following_index = i+2;
                following_index < float_count; ++following_index) {
                if (cur_num == atof(argv[following_index])) {
                    cur_num_count += 1;
                }
            }

            if (cur_num_count == most_appearance_count) {
                if (mac_printed == 0) {
                    printf("Useimmiten esiintyneet (%d kertaa):", cur_num_count);
                    mac_printed += 1;
                }

                printf(" %f", cur_num);
            }
        }
        printf("\n");
    }
    */

    return 0;
}
