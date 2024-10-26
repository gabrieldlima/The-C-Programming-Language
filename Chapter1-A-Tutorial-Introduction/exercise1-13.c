/*
|Exercise 1-13: Write a program to print a histogram of the lengths of words in|
|its input. It is easy to draw the histogram with the bars horizontal; a verti-|
|cal orientation is more challenging.                                          |
*/

#include <stdio.h>

#define MAXHIST 15          // max length of histogram
#define MAXWORD 11          // max length of a word
#define IN 1                // inside a word
#define OUT 0               // outside a word

// Print horizontal histogram
int main(void)
{
    int c, nc, state;       
    int len;                // length of each bar
    int maxvalue;           // maximum value for wl[];
    int overflow;           // number of overflow words
    int wl[MAXWORD];        // word length counters

    state = OUT;
    nc = 0;                 // number of chars in a word
    overflow = 0;           // number of words >= MAXWORD
    for (int i = 0; i < MAXWORD; ++i)
    {
        wl[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            if (nc > 0)
            {
                if (nc < MAXWORD)
                {
                    ++wl[nc];
                }
                else
                {
                    ++overflow;
                }
            }
            nc = 0;
        }
        else if (state == OUT)
        {
            state = IN;
            nc = 1;         // beginning of a word
        }
        else
        {
            ++nc;           // inside a word
        }
    }

    maxvalue = 0;
    for (int i = 1; i < MAXWORD; ++i)
    {
        if (wl[i] > maxvalue)
        {
            maxvalue = wl[i];
        }
    }

    for (int i = 1; i < MAXWORD; ++i)
    {
        printf("%5d - %5d: ", i, wl[i]);
        if (wl[i] > 0)
        {
            if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
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

        if (overflow > 0)
        {
            printf("There are %d words >= %d\n", overflow, MAXWORD);
        }
    }

    return 0;
}
