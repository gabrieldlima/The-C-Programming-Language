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
int atoi(int c);


int main(void)
{
    char string1[BYTES];
    char string2[BYTES];
    char c;

    printf("Shorthand notation to be expanded: (Example: a-z, 0-9, ...)\n>>> ");
    scanf("%s", string1);

    expand(string1, string2);

    return 0;
}

void expand(char s1[], char s2[])
{
    int i;
    int start = 0;
    int end = 0;

    for (i = 0; !(isdigit(s1[i])); ++i);

    start = atoi(s1[0]);
    end = atoi(s1[2]);

    if (start < end)
    {
        while (start <= end)
        {
            printf("%d ", start++);
        }
    }
    else if (start > end)
    {
        while (start >= end)
        {
            printf("%d ", start--);
        }
    }
    putchar('\n');
}


int atoi(int c)
{
    int number = 0;

    number = 10 * number + (c - '0');
    
    return number;
}
