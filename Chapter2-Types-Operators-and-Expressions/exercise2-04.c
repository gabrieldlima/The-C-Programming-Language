/*
|Exercise 2-04: Write an alternative version of squeeze(s1, s2) that deletes   |
|each character in s1 that matches any character in the string s2.             |
*/

#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]);

char string1[] = "Gabriel";
char string2[] = "Gustavo";

int main(void)
{
    squeeze(string1, string2);

    printf("%s\n", string1);
    printf("%s\n", string2);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int c;

    int size = strlen(s2);
    for (int i = 0; i <= size; ++i)
    {
        c = s2[i];
        int i, j;

        for (i = j = 0; s1[i] != '\0'; i++)
        {
            if (s1[i] != c)
            {
                s1[j] = s1[i];
                j++;
            }
        }
        s1[j] = '\0';
    }
}
