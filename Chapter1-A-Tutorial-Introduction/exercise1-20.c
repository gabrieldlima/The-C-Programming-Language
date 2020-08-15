/*
|Exercise 1-20: Write a program detab that replaces tabs in the input with the |
|proper number of blanks to space to the next tab stop. Assume a fixed set of  |
|tab stops,say every n columns. Should n be a variable or a symbolic parameter?|
*/

#include <stdio.h>

#define TABINC 8                    // Tab increment size

int main(void)
{
    int c, nb, pos;

    nb = 0;                         // Number of blanks necessary
    pos = 1;                        // Position of char in line

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')              // Tab char
        {
            nb = TABINC - (pos - 1) % TABINC;
            
            while (nb > 0)
            {
                putchar(' ');
                ++pos;
                --nb;
            }
        }
        else if (c == '\n')         // Newline char
        {
            putchar(c);
            pos = 1;
        }
        else                        // All other chars
        {
            putchar(c);
            ++pos;
        }
    }

    return 0;
}
