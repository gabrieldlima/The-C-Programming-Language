/*
|Exercise 1-4: Write a program to print the correponding Celcius to Fahrenheit |
|table.                                                                        |
*/

#include <stdio.h>

int main(void)
{
    float fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celcius = lower;

    printf("%3c\t%6c\n", 'C', 'F');
    while (celcius <= upper)
    {
        fahr = (9.0 * celcius) / 5.0 + 32.0;
        printf("%3.0f\t%6.1f\n", celcius, fahr);
        celcius = celcius + step;
    }
    
    return 0;
}
