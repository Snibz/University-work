#include <stdio.h>
#include <stdlib.h>
#include "ykkosvalit.h"


UintPari ykkosValit(const char *syoteNimi, const char *tulosNimi)
{

    UintPari pari;
    int space = 32;
    int i = 0;
    unsigned int chars_read = 0;
    unsigned int chars_printed = 0;
    int last_char_index = 0;
    int last_char = 0;
    int chars_encountered = 0;
    int previous_was_space = 0;
    int space_was_printed = 0;
    int previous_printed = 0;
    int previous_read = 0;

    FILE *syote = fopen(syoteNimi, "r");
    FILE *tulos = fopen(tulosNimi, "a");

    while( (i = fgetc(syote)) != EOF)
    {

        if(chars_read == 0 || chars_encountered == 0)
        {
            /* if it's the start of the file, extra spaces are removed */
            if(i == space)
            {
                chars_read += 1;
                previous_was_space = 1;
                previous_read = i;

                continue;
            }
            else
            {
                int fputcreturn = fputc(i, tulos);
                chars_printed += 1;
                last_char = i;
                last_char_index = chars_read;
                chars_read += 1;
                chars_encountered = 1;
                previous_was_space = 0;
                previous_printed = i;
                previous_read = i;
                continue;
            }

        }
        else
        {
            /* Chars have been read, non-space chars */
            if(i == space)
            {

                if(previous_printed == space)
                {
                    /* double space, not copying this one */
                    chars_read += 1;
                    previous_read = i;
                    continue;
                }
                else
                {
                    int following = fgetc(syote);
                    chars_read += 1;
                    previous_read = following;
                    /* Now current i is space, but previous char is not */
                    /* We print current space if next char is not space or
                       newline */
                    if(following != space && following != 10)
                    {
                        int returnuseless = fputc(i, tulos);
                        chars_printed += 1;
                        returnuseless = fputc(following, tulos);
                        chars_printed += 1;
                        previous_printed = following;
                    }
                    else if(following == 10)
                    {
                        int returnuseless = fputc(following, tulos);
                        chars_printed += 1;
                        previous_printed = following;
                        chars_encountered = 0;
                    }
                    chars_read += 1;

                    continue;
                }

            }
            else
            {
                int fputcreturn = 0;
                if(previous_read == space && previous_printed != space && i != 10)
                {
                    int shit = fputc(space, tulos);
                    chars_printed += 1;
                }
                fputcreturn = fputc(i, tulos);

                if(i == 10)
                {
                    chars_encountered = 0;
                }
                else
                {
                    chars_encountered = 1;
                }

                previous_printed = i;
                chars_printed += 1;
                last_char = i;
                last_char_index = chars_read;
                previous_was_space = 0;
                /*chars_encountered = 1;*/

            }

            previous_read = i;
            chars_read += 1;
        }

    }

    pari.x = chars_read;
    pari.y = chars_printed;
    return pari;

}
