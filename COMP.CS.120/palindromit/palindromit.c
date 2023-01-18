#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>




int main(int argc, char *argv[])
{
    int i = 1;
    while (i <= argc - 1)
    {
        int string_i = 0;
        int length_of_string = 0;
        char upper_string[100];

        while (argv[i][length_of_string] != '\0')
        {
            ++length_of_string;
        }

        for (string_i = 0; string_i < length_of_string; ++string_i)
        {
            char current_char = argv[i][string_i];
            upper_string[string_i] = toupper(current_char);
        }
        /* Now upper_string should have the string in all upper*/

        if (length_of_string % 2 != 0)
        {
            /* odd number of characters */
            int inequality_count = 0;
            int string_first_end= 0;
            int string_last_end = length_of_string - 1;
            int string_middle_index = (length_of_string / 2) + 1;

            while (string_first_end != string_middle_index)
            {
                if (upper_string[string_first_end] != upper_string[string_last_end])
                {
                    inequality_count += 1;
                }
                ++string_first_end;
                --string_last_end;
            }
            if (inequality_count != 0)
            {
                /* Not a palindrome */
                printf("\"%s\": ei ole palindromi\n", argv[i]);
            }
            else
            {
                printf("\"%s\": on palindromi\n", argv[i]);
            }


        }
        else
        {
            /* Even number of characters. */
            int inequality_count = 0;
            int string_first_end = 0;
            int string_last_end = (length_of_string - 1);
            int first_end_end = (length_of_string / 2) - 1;
            int last_end_end = (length_of_string / 2);

            while (string_first_end < last_end_end)
            {

                if (upper_string[string_first_end] != upper_string[string_last_end])
                {
                    inequality_count += 1;
                }
                ++string_first_end;
                --string_last_end;
            }
            if (inequality_count != 0)
            {
                printf("\"%s\": ei ole palindromi\n", argv[i]);
            }
            else
            {
                printf("\"%s\": on palindromi\n", argv[i]);
            }

        }


        ++i;
    }








return 0;
}
