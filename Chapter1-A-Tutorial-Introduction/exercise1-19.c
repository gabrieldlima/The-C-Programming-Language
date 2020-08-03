/*
|Exercise 1-19: Write a function reverse(s) that reverses the character string |
|s. Use it to write a program that reverses its input a line at time.          |
*/

#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
void reverse(char s[]);

int main(void)
{
    char line[MAXLINE];

    while (getLine(line, MAXLINE) > 0)
    {
        reverse(line);
        printf("%s", line);
    }
    
    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c !=  '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

void reverse(char s[])
{
    int i, j;
    char temp;

    i = 0;

    while (s[i] != '\0')            // Find the end of string
    {
        ++i;
    }
    --i;                            // Back off from '\0
    if (s[i] == '\n')
    {
        --i;                        // Leave newline in place
    }
    j = 0;
    while (j < i)
    {
        temp = s[j];                // Swap the characters
        s[j] = s[i];
        s[i] = temp;
        --i;
        ++j;
    }
}
