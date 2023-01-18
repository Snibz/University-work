#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool is_not_divisible(int dividee, int divisor) {

    if ( divisor == 1) {
        return false;
    }


    if ( dividee % divisor != 0) {
        return true;
    } else {
        return false;
    }

}

int main(int argc, char *argv[]) {

    /* So, argv1 is smallest, argv2 largest, all possible
       following args are numbers to which division is checked
       on */

    if (argc > 3) {
        /* this means there are at least the smallest and
           largest, which will be printed. Also at least 1 additional


           Need to go through every number in the array
           in a loop. And if division params exist,
           need to do divisions on every loop. */

        int lowest = atoi(argv[1]);
        int highest = atoi(argv[2]);
        int current = lowest;
        int print_count = 0;
        /* Far as I understand, there will be at least
           1 possible arg, so argv 3 is guaranteed to exist.
        */
        for (current = lowest; current <= highest; ++current) {

            int add_arg_count = argc - 3;
            int handled_add_args = 0;
            int add_arg_index = 3;
            int successful_checks = 0;

            while (handled_add_args < add_arg_count) {

                int arg_num = atoi(argv[add_arg_index]);
                if (is_not_divisible(current, arg_num)) {
                    successful_checks += 1;
                }
                handled_add_args += 1;
                add_arg_index += 1;
            }

            if (successful_checks == add_arg_count) {

                if (print_count == 0) {
                    printf("%d", current);
                }
                else if (print_count > 0) {
                    printf(" %d", current);
                }

                print_count += 1;
            }
        }
        if (print_count > 0) {
            printf("\n");
        }
    }
    return 0;
}
