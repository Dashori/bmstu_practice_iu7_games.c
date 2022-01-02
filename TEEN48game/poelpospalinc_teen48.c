#include "poelpospalinc_teen48.h"

char teen48game(matrix_t matrix)
{
    int row = matrix.rows;
    int col = matrix.columns;

    char swipe = 'l';
    int p = 0;

    while (1)
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (matrix.matrix[i][j] == 0)
                {
                    if (i > 0 && matrix.matrix[i - 1][j] != 0)
                        return 'd';
                    if (i < row - 1 && matrix.matrix[i + 1][j] != 0)
                        return 'u';
                    if (j > 0 && matrix.matrix[i][j - 1] != 0)
                        return 'r';
                    if (j < col - 1 && matrix.matrix[i][j + 1] != 0)
                        return 'l';
                }

        for (int k = 2; k <= 8192; k *= 2)
        {
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                    if (matrix.matrix[i][j] == k)
                    {
                        if (i > 0 && matrix.matrix[i - 1][j] == k)
                            return 'd';
                        if (i < row - 1 && matrix.matrix[i + 1][j] == k)
                            return 'u';
                        if (j > 0 && matrix.matrix[i][j - 1] == k)
                            return 'r';
                        if (j < col - 1 && matrix.matrix[i][j + 1] == k)
                            return 'l';
                    }
        }

        p++;

        if (p > 128)
            break;
    }

    return swipe;
}
