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

int atoi(char sn[]);
int strl(char string[]);
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

    for (i; !(isdigit(s1[i])) && !(isalpha(s1[i])); ++i);

    




}


// Convert string to integer
int atoi(char sn[])
{
    int number, size, c;

    number = 0;
    size = strl(sn);

    for (int i = 0; i < size && (c = sn[i]); ++i)
    {
        number = 10 * number + (c - '0');
    }
    
    return number;
}


// Return the size of the string[]
int strl(char string[])
{
    int i = 0;

    while (string[i] != '\0')
    {
        ++i;
    }

    return i;
}
