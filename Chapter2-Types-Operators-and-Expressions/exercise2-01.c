/*
|Exercise 2-01: Write a program to determine the ranges of char, short, int and|
|long variables, both signed and unsigned, by printing appropriate values from |
|standard headers and by direct computation. Harder if you compute them: deter-|
|mine the ranges of the various floating-point types.                          |
*/

#include <stdio.h>
#include <limits.h>

int main(void)
{
    // Signed types
    printf("signed char min = %d\n", SCHAR_MIN);
    printf("signed char max = %d\n", SCHAR_MAX);
    printf("signed short min = %d\n", SHRT_MIN);
    printf("signed short max = %d\n", SHRT_MAX);
    printf("signed int min = %d\n", INT_MIN);
    printf("signed int max = %d\n", INT_MAX);
    printf("signed long min = %ld\n", LONG_MIN);
    printf("signed long max = %ld\n", LONG_MAX);
    
    // Unsigned types
    printf("unsigned char max = %u\n", UCHAR_MAX);
    printf("unsigned short max = %u\n", USHRT_MAX);
    printf("unsigned int max = %u\n", UINT_MAX);
    printf("unsigned long max = %lu\n", ULONG_MAX);

    return 0;
}
