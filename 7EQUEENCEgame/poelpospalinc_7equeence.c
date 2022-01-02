#include <stdio.h>
#include <limits.h>

long long sequence_game(int array[])
{
    long long number = LLONG_MIN;
    long long n = 1LL;
    int *b = array;
    int *e = array + 1000;

    for (int *p = b; p < e - 13; p++)
    {
        for (int *p2 = p; p2 < p + 13; p2++)
            n *= *p2;

        if (n > number)
            number = n;
        n =1LL;
    }
    
    return number;
}
