#include "poelpospalinc_num63rs.h"
#include <stdlib.h>
#include <stdio.h>

int test(int min, int max, int out, int *num_of_tests, int *failed_tests)
{
    int res = numbers_game(min, max);
    
    if (res != out)
    {
        printf("%d Failed\n", *num_of_tests);
        (*failed_tests)++;
        printf("%d %d\n", out, res);
    }
    printf("%d PASSED\n", *num_of_tests);
    (*num_of_tests)++;

    return EXIT_SUCCESS;
}

int main(void)
{
    int num_of_tests = 0;
    int failed_tests = 0;

    test(1, 10, 2520, &num_of_tests, &failed_tests);
    test(2, 10, 2520, &num_of_tests, &failed_tests);
    test(9, 10, 90, &num_of_tests, &failed_tests);
    test(8, 10, 360, &num_of_tests, &failed_tests);

    return failed_tests;
}
