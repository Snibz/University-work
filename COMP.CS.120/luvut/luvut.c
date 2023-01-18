#include <stdio.h>
#include <stdbool.h>

bool is_acceptable(int num) {
/* check if num is divisible by 2, 3 or 5.
   if num divisible by none, return true. Else false. */

    if (num % 2 != 0) {
        if (num % 3 != 0) {
            if (num % 5 != 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }


}




int main(void) {

    int cur_num = 1;

    for (cur_num = 1; cur_num < 101; ++cur_num) {

        if (is_acceptable(cur_num)) {


            if (cur_num == 97) {
                printf("%d\n", cur_num);
            } else {
                printf("%d ", cur_num);

            }
        }
    }

return 0;
}
