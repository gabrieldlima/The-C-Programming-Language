/*
|Exercise 1-14: Write a program to print a histogram of the frequencies of di- |
|ferents characters in its input.                                              |
*/

#include <stdio.h>
#include <ctype.h>

#define MAXHIST 15          // Max length of histogram
#define MAXCHAR 128         // Max different characters

// Print horizontal histogram freq. of different characters
int main(void)
{
    int c;                  
    int len;                // Length of each bar
    int maxvalue;           // Maximum value for cc[]
    int cc[MAXCHAR];        // Character counters 

    for (int i = 0; i < MAXCHAR; ++i)
    {
        cc[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c < MAXCHAR)
        {
            ++cc[c];
        }
    }

    maxvalue = 0;

    for (int i = 1; i < MAXCHAR; ++i)
    {
        if (cc[i] > maxvalue)
        {
            maxvalue = cc[i];
        }
    }

    for (int i = 1; i < MAXCHAR; ++i)
    {
        if (isprint(i))
        {
            printf("%5d - %c - %5d : ", i, i, cc[i]);
        }
        else
        {
            printf("%5d -    - %5d : ", i , cc[i]);
        }

        if (cc[i] > 0)
        {
            if ((len = cc[i] * MAXHIST / maxvalue) <= 0)
            {
                len = 1;
            }
        }
        else
        {
            len = 0;
        }
        
        while (len > 0)
        {
            
            putchar('*');
            --len;
        }
        putchar('\n');
    }

    return 0;
}
