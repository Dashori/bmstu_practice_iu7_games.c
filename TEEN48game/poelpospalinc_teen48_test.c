#include "poelpospalinc_teen48.h"
#include <stdio.h>

void transform(int **arr, int *buf, int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = buf + n * i;
}

void print_matrix(int **matrix, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main(void)
{

    int in[5][5] = {0};
    int *matrix_1[5];

    transform(matrix_1, *in, 4);

    for (int i = 0; i < 4; i++)
        for( int j = 0; j < 4; j++)
            matrix_1[i][j] = 2;
    matrix_1[0][1] = 4;
    matrix_1[1][1] = 4;

    print_matrix(matrix_1, 4);

    matrix_t test_1 = {4, 4, matrix_1};

    char c = teen48game(test_1);

    if (c == 'u')
        printf("OK\n");
    else
    {
        printf("NO\n");
        return 1;
    }

    int *matrix_2[5];

    transform(matrix_2, *in, 4);

    for (int i = 0; i < 4; i++)
        for( int j = 0; j < 4; j++)
            matrix_2[i][j] = 0;

    matrix_2[0][1] = 4;
    matrix_2[1][1] = 4;
    matrix_2[2][1] = 4;
    matrix_2[3][1] = 4;
    matrix_2[0][2] = 2;

    print_matrix(matrix_2, 4);

    matrix_t test_2 = {4, 4, matrix_2};

    char c_2 = teen48game(test_2);

    if (c_2 == 'l')
        printf("OK\n");
    else
    {
        printf("NO\n");
        return 1;
    }

    int *matrix_3[5];

    transform(matrix_3, *in, 4);

    for (int i = 0; i < 1; i++)
        for( int j = 0; j < 4; j++)
            matrix_3[i][j] = 4;
            
    for (int i = 1; i < 4; i++)
        for( int j = 0; j < 4; j++)
            matrix_3[i][j] = 2048;

    print_matrix(matrix_3, 4);

    matrix_t test_3 = {4, 4, matrix_3};
    char c_3 = teen48game(test_3);

    if (c_3 == 'l')
        printf("OK\n");
    else
    {
        printf("NO\n");
        return 1;
    }

    return 0;
}
