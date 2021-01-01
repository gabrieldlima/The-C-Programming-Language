/*
|Exercise 3-01: Our binary search makes two tests inside the loop, when one    |
|would suffice (at the price of more test outside). Write a version with only  |
|one test inside the loop and measure the difference in run-time.              |
*/

#include <stdio.h>


int original_binsearch(int x, int v[], int n);
int modified_binsearch(int x, int v[], int n);

int main(void)
{
    /*
    The difference in run-time is minimal. We did not gain much in performance  
    and lost some in code readability. The original code on page 58 K&R reads
    better from top to bottom.
    */

    return 0;
}

/* 
--------------------------------------------------------------------------------
MODIFIED CODE
--------------------------------------------------------------------------------
*/
int modified_binsearch(int x, int v[], int n)
{
    int start, mid, end;

    start = 0;
    end = n - 1;
    mid = (start + end) / 2;

    while (start <= end && x != v[mid])
    {
        if (x < v[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }   
        
        mid = (start + end) / 2;

        if (x == v[mid])
        {
            return mid;
        }
        else
        {
            return -1;
        }
    }
}

/*
--------------------------------------------------------------------------------
ORIGINAL CODE
--------------------------------------------------------------------------------
*/
int original_binsearch(int x, int v[], int n)
{
    int start, mid, end;

    start = 0;
    end = n - 1;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (x < v[mid])
        {
            end = mid - 1;
        }
        else if (x > v[mid])
        {
            start = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}
