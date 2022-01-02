#include "poelpospalinc_split.h"

int split(const char *string, char **matrix, const char symbol)
{
    int i = 0, j = 0, k = 0;
    matrix[0][0] = 0;
    while (string[k])
    {
        if (symbol != string[k])
            matrix[i][j++] = string[k];
        else
        {
            matrix[i++][j] = 0;
            j = 0;
        }
        k++;
    }
    matrix[i++][j] = 0;
    return i;
}
