/*
|Exercise 2-02: Write a loop equivalent to the for loop above without using && |
|or ||.                                                                        |
*/

#include <stdio.h>

enum loop { NO, YES};
enum loop okloop = YES;

int main(void)
{
    int c;
    int i = 0;
    int lim = 10;
    char s[lim];

    while (okloop == YES)
    {
        if (i >= lim-1)                 // Outside of valid range?
        {
            okloop = NO;
        }
        else if ((c = getchar()) == '\n')
        {
            okloop = NO;
        }
        else if (c == EOF)              // End of file?
        {
            okloop = NO;
        }
        else
        {
            s[i] = c;
            ++i;
        }   
    }

    return 0;
}
