#include "gotokoe.h"

int max2D(int **t2d, int kork, int lev)
{
    int largest = 0;
    int row_i = 0;
    int object_i = 0;
    int current = 0;

BEGIN:
    if(row_i == kork)
        goto END;
    if(object_i == lev)
        goto NEXTROW;
    current = t2d[row_i][object_i];
    if(current > largest)
        goto SETLARGEST;
    goto FORWARD;
SETLARGEST:
    largest = current;
    goto FORWARD;
NEXTROW:
    row_i += 1;
    object_i = 0;
    goto BEGIN;
FORWARD:
    object_i += 1;
    goto BEGIN;
END:
    return largest;

}
