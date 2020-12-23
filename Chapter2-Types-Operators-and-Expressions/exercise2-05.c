/*
|Exercise 2-05: Write the function any(s1, s2), which returns the first loca-  |
|tion in the string s1 where any character from the string s2 occurs, or -1 if |
|s1 contains no characters from s2.(The standard library function strpbrk does |
the same job but returns a pointer to the location)                            |
*/

#include <stdio.h>

int any(char s1[], char s2[]);

char string1[] = "Gabriel";
char string2[] = "Programmer";


int main(void)
{
    
    printf("1º String: %s\n", string1);
    printf("2º String: %s\n", string2);
    printf("The first location was in position %d.\n", any(string1, string2));

    return 0;
}


int any(char s1[], char s2[])
{
    int c;
    int location = 0;
    int count = 0;

    for (int i = 0; s2[i] != '\0'; ++i)
    {
        c = s2[i];

        for (int j = 0; s1[j] != '\0'; ++j)
        {
            if (s1[j] == c)
            {
                count++;
                location = j;
                break;
            }
        }
        
        if (location != 0)
            break;
    }

    if (count != 0)
        return location + 1;
    else
        return -1;
}
