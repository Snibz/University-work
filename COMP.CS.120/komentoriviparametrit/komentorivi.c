#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int current_param = 1;

    while (current_param < argc) {

       int length = strlen(argv[current_param]);


        printf("%d: %s (pituus: %d)\n",
               current_param, argv[current_param], length);
        ++current_param;
    }

    return 0;
}
