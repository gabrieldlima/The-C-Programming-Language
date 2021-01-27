/*
|Exercise 3-03: Write a function expand(s1,s2) that expands shorthand notations|
|like a-z in the string s1 into the equivalent complete list abc...xyz in s2.  |
|Allow for letters of either case and digits, and be prepared to handle cases  |
|like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is take  |
|literally.                                                                    |
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
    int num_start = 0;
    int num_end = 0;
    int alpha_start = 0;
    int alpha_end = 0;
    
    int count = 0;
    int i = 0;
    
    // Check if the string s1 is a valid input
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
            num_start = 10 * num_start + (s1[--i] - '0');
            num_end = 10 * num_end + (s1[++i] - '0');

            i = 0;
            if (num_start <= num_end)
            {
                for (int j = num_start; j <= num_end; ++j)
                {
                    s2[i++] = j + '0';
                }
            }
            else if (num_start >= num_end)
            {
                for (int j = num_start; j >= num_end; --j)
                {
                    s2[i++] = j + '0';
                }
            }
        }

        // Alphabetic notation block
        if (isalpha(s1[i]) && isalpha(s1[++i]))
        {
            alpha_start = toupper(s1[--i]);
            alpha_end = toupper(s1[++i]);

            i = 0;
            if (alpha_start <= alpha_end)
            {
                for (int j = alpha_start; j <= alpha_end; ++j)
                {
                    s2[i++] = j;
                }

                for (int k = i; k < BYTES; ++k)
                    s2[k] = '\0';
            }
            else if (alpha_start >= alpha_end)
            {
                for (int j = alpha_start; j >= alpha_end; --j)
                {
                    s2[i++] = j;
                }

                for (int k = i; k < BYTES; ++k)
                    s2[k] = '\0';
            }
        }
    }
}
