#include <string.h>
#include <stdio.h>
#include "poelpospalinc_split.h"

int test(const char *str, const char d, char **split_r, int row, char str_out[][20], int *num_of_tests,
    int *failed_tests)
{
    (*num_of_tests)++;
    int n = split(str, split_r, d);

    if (n != row)
    {
        printf("%d  %d\n%d Failed\n",row, n, *num_of_tests);
        failed_tests++;
        return EXIT_FAILURE;
    }
    
    for (int i = 0; i < n; i++)
        if (strcmp(split_r[i], str_out[i]))
        {
            printf("%s | %s", split_r[i], str_out[i]);
            printf("%d Failed\n", *num_of_tests);
            failed_tests++;
            return EXIT_FAILURE;
        }

    printf("%d Passed\n", *num_of_tests);

    return EXIT_SUCCESS;
}
void transform(char **arr, char *buf, int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = buf + n * i;
}

int main(void)
{
    int failed_tests = 0;
    int num_of_tests = 0;

    char in[1024][1024] = {0};

    char* in_list_1[1024];
    transform(in_list_1, *in, 1024);
    const char test_01_in[] = "I'am Lyosha ";
    char test_01_out[][20] = { "I'am", "Lyosha", ""};
    test(test_01_in, ' ', in_list_1, 3, test_01_out, &num_of_tests, &failed_tests);

    char* in_list_2[1024];
    transform(in_list_2, *in, 1024);
    const char test_02_in[] = "   I'am       Dasha";
    char test_02_out[][20] = {"","","","I'am","","","","","","", "Dasha" };
    test(test_02_in, ' ', in_list_2, 11, test_02_out, &num_of_tests, &failed_tests);

    char* in_list_3[1024];
    transform(in_list_3, *in, 1024);
    const char test_03_in[] = "   rrr ";
    char test_03_out[][20] = {"","","","rrr",""};
    test(test_03_in, ' ', in_list_3, 5, test_03_out, &num_of_tests, &failed_tests);

    char* in_list_4[1024];
    transform(in_list_4, *in, 1024);
    const char test_04_in[] = "   f";
    char test_04_out[][20] = { "","","","f" };
    test(test_04_in, ' ', in_list_4, 4, test_04_out, &num_of_tests, &failed_tests);

    char* in_list_5[1024];
    transform(in_list_5, *in, 1024);
    char test_05_in[] = "Hello,! world!";
    char test_05_out[][20] = { "Hello,!", "world!" };
    test(test_05_in, ' ', in_list_5, 2, test_05_out, &num_of_tests, &failed_tests);


    char *in_list_6[1024];
    transform(in_list_6, *in, 1024);
    char test_06_in[] = "";
    char test_06_out[][20] = {""};
    test(test_06_in, '!', in_list_6, 1, test_06_out, &num_of_tests, &failed_tests);

    char* in_list_7[1024];
    transform(in_list_7, *in, 1024);
    char test_07_in[] = "boook";
    char test_07_out[][20] = {"boook"};
    test(test_07_in, '.', in_list_7, 1, test_07_out, &num_of_tests, &failed_tests);

    char* in_list_8[1024];
    transform(in_list_8, *in, 1024);
    char test_08_in[] = "    ";
    char test_08_out[][20] = {"","","","",""};
    test(test_08_in, ' ', in_list_8, 5, test_08_out, &num_of_tests, &failed_tests);

    return failed_tests;
}
