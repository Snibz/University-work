#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_sqrt(double number) {

    return sqrt(number);
}


int main(int argc, char *argv[]) {

    int handled_numbers = 0;
    int number_count = argc - 2;
    int argv_index = 2;
    int decimals = atoi(argv[1]);

    while (handled_numbers < number_count) {

        double current_number = atof(argv[argv_index]);
        printf("sqrt(%.*f) = %.*f\n", decimals, current_number,
               decimals, calculate_sqrt(current_number));
        handled_numbers += 1;
        argv_index += 1;

    }


return 0;
}
