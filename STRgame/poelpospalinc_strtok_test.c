#include <stdio.h>
#include "poelpospalinc_strtok.h"

int strtok_cmp(char *string, char const *delim, char *std)
{
    char *tmp = strtok(string, delim);
    
    return  tmp != std;
}

int test(char *in, char *delim, char *out, int *num_of_tests, int *failed_tests)
{

    if (strtok_cmp(in, delim, out))
    {
        printf("%d Failed\n", *num_of_tests);
        (*failed_tests)++;
        return EXIT_FAILURE;
    }
    else
        printf("%d Passed\n", *num_of_tests);
    (*num_of_tests)++;

    return EXIT_SUCCESS;
}

int main(void)
{
    int failed_tests = 0;
    int num_of_tests = 0;

    num_of_tests++;

    char test_01_in[] = "";
    char *test_01_out = NULL;
    test(test_01_in, " ", test_01_out, &num_of_tests, &failed_tests);

    char test_02_in[] = "I am Lyosha";
    char *test_02_out = test_02_in;
    test(test_02_in, " ", test_02_out, &num_of_tests, &failed_tests);

    char test_03_in[] = "       ";
    char *test_03_out = NULL;
    test(test_03_in, " ", test_03_out, &num_of_tests, &failed_tests);

    char test_04_in[] = "wer4rDkfoerf";
    char *test_04_out = test_04_in;
    test(test_04_in, " ", test_04_out, &num_of_tests, &failed_tests);

    char test_05_in[] = "I am Dasha";
    char *test_05_out = test_05_in;
    test(test_05_in, " ", test_05_out, &num_of_tests, &failed_tests);

    char *test_06_in = NULL;
    char *test_06_out = test_05_in + 2;
    test(test_06_in, " ", test_06_out, &num_of_tests, &failed_tests);

    char test_07_in[] = "Hello!,   world...";
    char *test_07_out = test_07_in;
    test(test_07_in, " ,!", test_07_out, &num_of_tests, &failed_tests);

    char *test_08_in = NULL;
    char *test_08_out = test_07_in + 10;
    test(test_08_in, " ,!", test_08_out, &num_of_tests, &failed_tests);

    return failed_tests;
}
