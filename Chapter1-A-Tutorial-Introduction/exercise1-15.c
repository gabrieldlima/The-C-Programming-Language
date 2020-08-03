/*
|Exercise 1-15: Rewrite the temperature conversion program of Section 1.2 to   |
|use a function for conversion.                                                |
*/

#include <stdio.h>

float celcius(float farh);

int main(void)
{
    int lower = 0;          // Lower limit of temperature table
    int upper = 300;        // Upper limit
    int step = 20;          // Step size
    float farh = lower;

    while (farh <= upper)
    {
        printf("%3.0f\t%6.1f\n", farh, celcius(farh));
        farh += step;
    }

    return 0;
}

// celcius(): convert farh into celcius
float celcius(float farh)
{
    return (5.0 / 9.0) * (farh - 32.0);
}
