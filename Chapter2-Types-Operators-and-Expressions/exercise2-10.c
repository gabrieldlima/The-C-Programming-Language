/*
|Exercise 2-10: Rewrite the function lower, which converts upper case letters  |
|to lower case, with a conditional expression instead of if-else.              |
*/

#include <stdio.h>
#include <ctype.h>

int lower(int);


int main(void)
{
    int c;

    printf("Enter a character: ");
    while (!(isalpha(c = getchar())))
    {
        if (c == 10)
            continue;

        printf("%c is not a character! Try again.\n", c);
        printf("Enter a character: ");
    }

    printf("%c\n", lower(c));

    return 0;
}


int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
