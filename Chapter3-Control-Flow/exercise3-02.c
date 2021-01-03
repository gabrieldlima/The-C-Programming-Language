/*
|Exercise 3-02: Write a function escape(t,s) that converts characters like new-|
|line and tab into visible escape sequences like \n and \t as it copies the    |
|string t to s. Use a switch. Write a function for the other direction as well,|
|converting escape sequences into real characters.                             |
*/

#include <stdio.h>

#define BYTES 32

void escape(char s[], char t[]);


int main(void)
{
    // Declaration and initialization of objects
    int c, i;
    char s_string[BYTES];
    char t_string[BYTES];

    for (int i = 0; i < BYTES; ++i)
    {
        s_string[i] = '\0';
        t_string[i] = '\0';
    }


    // User input
    i = 0;
    printf("Enter a string: ");
    while (i < BYTES - 1 && (c = getchar()) != EOF && c != '\n')
    {
        t_string[i++] = c;
    }
    t_string[i] = '\n';


    // Program output
    escape(s_string, t_string);

    printf("%s", t_string);
    printf("%s\n", s_string);

    return 0;
}


void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;

            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;

            default:
                s[j++] = t[i];
                break;
        }
    }

    s[j] = '\0';
}
