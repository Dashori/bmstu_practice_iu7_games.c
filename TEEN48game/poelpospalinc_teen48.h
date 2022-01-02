#ifndef _TEEN48_H_
#define _TEEN48_H_

typedef struct
{
    int rows;
    int columns;
    int **matrix;
} matrix_t;

char teen48game(matrix_t matrix);

#endif
