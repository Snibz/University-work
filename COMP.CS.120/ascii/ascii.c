#include <stdio.h>
#include <stdlib.h>




int main(int argc, char* argv[]) {

    /* So, as arguments the tester enters
       the number of the first ascii to print and
       the number of the last. Then, program will print
       on each own line the ascii number and the respective
       character. */

    /* argv[0] is program name, starting from argv[1] onwards
       the elements are arguments. So, argv[1] is the first
       ascii to print. argv[2] the last. */

    int lowest = atoi(argv[1]);
    int highest = atoi(argv[2]);

    int current = 0;

    for (current = lowest; current < highest+1; ++current) {
        printf("%d: %c\n", current, current);
    }



    return 0;
}
