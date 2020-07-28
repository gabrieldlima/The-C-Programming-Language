/*
|Exercise 1-8: Write a program to count blanks, tabs and newlines.             |
*/

#include <stdio.h>

int main(void)
{
    int c;
    int blanks, tabs, newlines;

    tabs = 0;
    blanks = 0;
    newlines = 0;    

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            ++tabs;
        }
        if (c == ' ')
        {
            ++blanks;
        }
        if (c == '\n')
        {
            ++newlines;
        }
    }

    printf("Tabs: %d\nBlanks: %d\nNewlines: %d\n", tabs, blanks, newlines);

    return 0;
}
