/*
|Exercise 1-16: Revise the main routine of the longest-line program so it will |
|correctly print the length of arbitrarily long input lines, and as much as    |
|possible of the text.                                                         |
*/

#include <stdio.h>

#define MAXLINE 1000            // Maximum input line size

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;                    // Current line length
    int max;                    // Maximum length seen so far
    char line[MAXLINE];         // Current input line
    char longest[MAXLINE];      // Longest line saved here

    max = 0;

    while ((len = getLine(line, MAXLINE)) > 0)
    {
        printf("%d, %s", len, line);
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)                // There was a line
    {
        printf("%s", longest);
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

// copy(): copy "from" into "to"; assume to is big enough
void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}
