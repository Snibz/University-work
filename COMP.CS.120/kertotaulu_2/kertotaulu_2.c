#include <stdlib.h>
#include <stdio.h>

int calculate_width(int number) {

    int width_number = 2;
    int division_result = number;

    while (division_result > 0) {
        division_result = division_result / 10;
        if (division_result > 0) {
            width_number += 1;
        }
    }
    return width_number;
}


int main(int argc, char *argv[]) {

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int d = atoi(argv[4]);

    int row_length = b - a + 1;

    int current_top_number = a;
    int current_leftmost_number = c;

    int largest_number = b * d;
    int width = calculate_width(largest_number);

    int i = 0;

    /*
    int times_printed_empty = 0;
    while (times_printed_empty < width) {
        printf("");
        times_printed_empty += 1;
    } */
    printf("%*.*d", width, 0, 0);

    while (current_top_number <= b) {
        printf("%*d", width, current_top_number);
        current_top_number += 1;
    }
    printf("\n");

    for (i = current_leftmost_number; i <= d; ++i) {
        int multiplied = 0;
        int current_column_number = a;

        printf("%*d", width, i);
        while (multiplied < row_length) {
            int number_to_print = i * current_column_number;
            printf("%*d", width, number_to_print);

            multiplied += 1;
            current_column_number += 1;
        }
        printf("\n");



    }




    return 0;
}
