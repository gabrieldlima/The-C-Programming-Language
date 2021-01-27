/*
|Exercise 3-03: Write a function expand(s1,s2) that expands shorthand notations|
|like a-z in the string s1 into the equivalent complete list abc...xyz in s2.  |
|Allow for letters of either case and digits, and be prepared to handle cases  |
|like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is take  |
|literally.                                                                    |
*/

#include <stdio.h>
#include <ctype.h>

#define BYTES 32

void expand(char s1[], char s2[]);


// Main function
int main(void)
{
    char string1[BYTES];
    char string2[BYTES];
    int c, i;

    // Input
    printf("Shorthand notation to be expanded: (Example: a-z, 0-9, ...)\n>>> ");
    i = 0;
    while (i < BYTES && (c = getchar()) != EOF)
    {        
        if (isdigit(c) || isalpha(c))
        {
            string1[i++] = c;
        }

        if (c == '\n')
        {
            while (i < BYTES)
            {
                string1[i] = '\0';
                i++;
            }
        }
    }

    expand(string1, string2);

    // Output
    for (i = 0; string2[i] != '\0'; ++i)
    {
        printf("%c ", string2[i]);
    }
    putchar('\n');

    return 0;
}


// Expand string s1[] to s2[]
void expand(char s1[], char s2[])
{
    int start = 0;
    int end = 0;
    int count = 0;
    int i = 0;
    
    for (int i = 0; i < BYTES; ++i)
    {
        if (isdigit(s1[i]) || isalpha(s1[i]))
        {
            ++count;
        }
    }

    if (count >= 2)
    {
        // Numeric notation block
        if (isdigit(s1[i]) && isdigit(s1[++i]))
        {
            start = 10 * start + (s1[--i] - '0');
            end = 10 * end + (s1[++i] - '0');

            i = 0;
            if (start <= end)
            {
                for (int j = start; j <= end; ++j)
                {
                    s2[i++] = j + '0';
                }
            }
            else if (start >= end)
            {
                for (int j = start; j >= end; --j)
                {
                    s2[i++] = j + '0';
                }
            }
        }
    }
}
