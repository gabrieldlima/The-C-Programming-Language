/*
|Exercise 1-21: Write a program entab that replaces strings of blanks by the   |
|minimum number of tabs and blanks to achieve the same spacing. Use the same   |
|tab stops as for detab. When either a tab or a single blank would suffice to  |
|reach a tab stop, which should be given preference?                           |
*/

#include <stdio.h>

#define TABINC 8                    // Tab increment size

int main(void)
{
    int c, nb, nt, pos;

    nb = 0;                         // # of blanks necessary
    nt = 0;                         // # of tabs necessary
    for (pos = 1; (c = getchar()) != EOF; ++pos)
    {
        if (c == ' ')
        {
            if (pos % TABINC != 0)
            {
                ++nb;               // Increment  # of blanks
            }
            else
            {
                nb = 0;             // Reset # of blanks
                ++nt;               // One more tab
            }
        }
        else
        {
            for ( ; nt > 0; --nt)
            {
                putchar('\t');      // Output tab(s)
            }
            
            if (c == '\t')          // Forget the blank(s)
            {
                nb = 0;
            }
            else                    // Output blanks
            {
                for ( ; nb > 0; --nb)
                {
                    putchar(' ');
                }
            }            
        }
        putchar(c);
        if (c == '\n')
        {
            pos = 0;
        }
        else if (c == '\t')
        {
            pos = pos + (TABINC - (pos - 1) % TABINC) - 1; 
        }
    }

    return 0;
}
