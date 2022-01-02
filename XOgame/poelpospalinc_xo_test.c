#include <stdio.h>
#include "poelpospalinc_xo.h"

void print(char a[][5], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    char a[5][5];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a[i][j] = ' ';

    for (int i = 0; i < 26; i += 2)
    {
        a[xogame(a, 3, 'X') / 3][xogame(a, 3, 'X') % 3] = 'X';
        print(a, 3);
        a[xogame(a, 3, 'O') / 3][xogame(a, 3, 'O') % 3] = 'O';
        print(a, 3);
    }
    a[xogame(a, 3, 'X') / 3][xogame(a, 3, 'X') % 3] = 'X';
    print(a, 3);
    
    return 0;
}
