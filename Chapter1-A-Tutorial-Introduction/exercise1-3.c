/*
|Exercise 1-3: Modify the temperature conversion program to print a heading    |
|above the table.                                                              |
*/

#include <stdio.h>

int main(void)
{
    float farh, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    farh = lower;

    printf("%3c\t%6c\n", 'F', 'C');
    while (farh <= upper)
    {
        celcius = (5.0 / 9.0) * (farh - 32);
        printf("%3.0f\t%6.1f\n", farh, celcius);
        farh = farh + step;
    }

    return 0;
}
