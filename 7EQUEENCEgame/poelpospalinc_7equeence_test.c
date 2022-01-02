#include "poelpospalinc_7equeence.h"
#include <stdlib.h>
#include <stdio.h>

void make_arr_1(int arr[])
{
    for(size_t i = 0; i < 1000; i++)
        arr[i] = 2;
}

void make_arr_2(int arr[])
{
    size_t i = 0;

    while (i < 1000)
    {
        arr[i++] = 1;
        arr[i++] = 2;
        arr[i++] = 3;
    }

}

void test(int arr[], long long std, int *num_of_tests, int *failed_tests)
{
    long long res = sequence_game(arr);

    if (res != std)
    {
        printf("%d Failed\n", *num_of_tests);
        (*failed_tests)++;
        printf("%lld %lld\n", std, res);
    }
    printf("%d PASSED\n", *num_of_tests);
    (*num_of_tests)++;
}

int main(void)
{
    int num_of_tests = 0;
    int failed_tests = 0;
    int arr[1000];

    make_arr_1(arr);
    test(arr, 8192LL, &num_of_tests, &failed_tests);
    make_arr_2(arr);
    test(arr, 3888LL, &num_of_tests, &failed_tests);
    
    return failed_tests;
}
