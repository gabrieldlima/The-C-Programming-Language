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
    int temp, n;

    // Input
    printf("Shorthand notation to be expanded: (Example: a-z, 0-9, ...)\n>>> ");
    scanf("%s", string1);

    expand(string1, string2);

    return 0;
}


// Expand string s1[] to s2[]
void expand(char s1[], char s2[])
{
    int i = 0;
    int j = 0;
    int start = 0;
    int end = 0;;
    
    for (i; !(isdigit(s1[i])) && !(isalpha(s1[i])); ++i); 

    // Numeric notation expanded
    if (isdigit(s1[i]))
    {
        start = 10 * start + (s1[i++] - '0');
        
        for (j = i; !(isdigit(s1[j])); ++j); 

        end = 10 * end + (s1[j] - '0');

        if (start < end)
        {
            for (int i = start; i <= end; ++i)
            {
                printf("%d ", i);
            }   
        }
        else
        {
            for (int i = start; i >= end; --i)
            {
                printf("%d ", i);
            }   
        }
        putchar('\n');
    }
}
