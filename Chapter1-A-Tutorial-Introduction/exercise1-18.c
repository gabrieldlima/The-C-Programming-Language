/*
|Exercise 1-18: Write a program to remove trailing blanks and tabs from each   |
|line of input, and to delete entirely blank lines.                            |
*/

#include <stdio.h>

#define MAXLINE 1000            // Maximum input line size

int getLine(char line[], int maxline);
int removeBlanks(char s[]);

int main(void)
{
    char line[MAXLINE];

    while (getLine(line, MAXLINE) > 0)
    {
        if (remove(line) > 0)
        {
            printf("%s", line);
        }
    }
    return 0;
}

// getline(): read a line into s, return lenght
int getLine(char s[], int lim)
{
    int c, i, j;
    j = 0;

    for (i = 0; (c = getchar()) != EOF && c !=  '\n'; ++i)
    {
        if (i < lim - 2)
        {
            s[j] = c;           // Line still in boundaries
            ++j;
        }
    }

    if (c == '\n')
    {
        s[j] = c;
        ++j;
        ++i;
    }

    s[i] = '\0';

    return i;
}

// remove(): remove trailing blanks and tabs from character string s
int removeBlanks(char s[])
{
    int i = 0;

    while (s[i] != '\n')        // Find newline character
    {
        ++i;
    }
    --i;                        // Back off from '\n'

    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
    {
        --i;
    }

    if (i >= 0)                 // Is it a noblank line?
    {
        ++i;
        s[i] = '\n';            // Put newline character back
        ++i;
        s[i] = '\0';            // Termite the string
    }

    return i;
}
