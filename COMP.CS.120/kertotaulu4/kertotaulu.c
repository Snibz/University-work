#include <stdlib.h>
#include <stdio.h>
#include "kertotaulu.h"

char ** luo_kertotaulu_mjt(uint a, uint b, uint c, uint d)
{
    /* Create via dynamic memory allocation a table of multiplications.
       the top row has numbers from a to b, with the first cell being empty.
       The leftmost column has numbers from c to d, the same first cell being
       empty.
    */
    /* The table is presented as rows of strings. They are sprintfed, so dynamic
       memory allocation is a must.
       The widths of each column are determined by the widest number in any cell
       of said column. So, the widths of columns need to be calculated first.
    */

    int i = 0;
    int j = 0;
    int row_width = 0;
    int column_count = b - a + 2;
    int row_count = d - c + 2;
    int spaces = column_count - 1;
    int chars_written = 0;
    char space[] = " ";

    char **table;

    int column_widths[100] = {0};

    for(i=0; i<column_count; ++i)
    {
        /* Calculate column widths in a loop */
        /* These widths will only include the widest num in the
           column, not the spaces between the columns */
        int largest = 0;
        int temp = 0;
        int width = 1;

        if(i==0)
        {
            largest = d;
        }
        else
        {
            largest = d * (a + i - 1);
        }
        temp = largest;
        for(temp = largest; temp > 9; temp /= 10)
        {
            /* If temp is greater than 9, divide it by 10
               and increase width by 1. */
               ++width;
        }
        /* Now width has the width of this column's cell. */
        column_widths[i] = width;
        row_width += width;
    }
    /* Now we know the widths of each column, and thus may calculate
       the width of each row. */
    /* 1 space separates each column from eachother, with
       the border columns not having spaces on the border sides
    */
    row_width += spaces;
    /* Add the endline char to width here */
    row_width += 1;
    /* Now row_width should have an accurate number. */

    table = malloc(row_count*sizeof(char *));
    for(i=0; i<row_count; ++i)
    {
        table[i] = malloc(row_width*sizeof(char));
    }
    /* Now table's memory should be allocated.
       Next is to calculate and print the actual rows.
       Loop for each row, loop for each cell in row
    */
    i=0;
    for(i=0; i<row_count; ++i)
    {
        /* This is the outer array, the table */
        j=0;
        chars_written = 0;
        for(j=0; j<column_count; ++j)
        {
            uint number = 0;
            /* Inner array, row */
            if(i == 0 && j == 0)
            {
                /* This slot is empty, will try to print
                width amount of spaces */
                while(chars_written <= column_widths[0])
                {
                    chars_written =
                    chars_written +
                    sprintf(&table[i][chars_written], "%s", space);
                }
                continue;
            }

            else if( i == 0)
            {
                /* if it's the topmost row */
                number = a + j - 1;
            }
            else if(j == 0)
            {
                /* if it's the first column */
                number = c + i - 1;
            }
            else
            {
                /* Not any significant border cell */
                number = (c+i-1)*(a+j-1);
            }


            chars_written =
            chars_written +
            sprintf(&table[i][chars_written], "%*u", column_widths[j], number);
            /* If the cell is not last of row, a space must be printed */

            if(j < column_count - 1)
            {
                chars_written =
                chars_written +
                sprintf(&table[i][chars_written], "%s", space);
            }
        }
    }
    return table;
}
