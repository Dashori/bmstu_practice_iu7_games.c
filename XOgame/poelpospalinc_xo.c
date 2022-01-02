#include <stdio.h>
#include <stdlib.h>
#include "poelpospalinc_xo.h"

int xogame(char **bf, const int field_size, const char symb)
{
    // Тут могла бы быть Ваша реклама :P
    int i;
    int j;
    char s, as;

    if (symb == 'X')
    {
        s = 'X';
        as = 'O';
    }
    else
    {
        s = 'O';
        as = 'X';
    }
    char t[5][5];

    for (i = 0; i < field_size; i++)
        for (j = 0; j < field_size; j++)
            t[i][j] = bf[i][j];
    int g = 1;

    for (int k = 0; k < 4; k++)
    {
        if (g)
        {
            for (int h = 0; h < field_size / 2 + 1; h++)
            {
                int f = 0;

                for (int l = 0; l < field_size; l++)
                    if (t[h][l] == s)
                        f++;

                if (f == field_size - 1)
                    for (int l = 0; l < field_size; l++)
                        if (t[h][l] == ' ')
                        {
                            t[h][l] = s;
                            g = 0;
                        }

                if (!g)
                    break;
            }
            if (g)
            {
                int f = 0;

                for (int l = 0; l < field_size; l++)
                    if (t[l][l] == s)
                        f++;

                if (f == field_size - 1)
                    for (int l = 0; l < field_size; l++)
                        if (t[l][l] == ' ')
                        {
                            t[l][l] = s;
                            g = 0;
                        }
            }
        }
        turn(t, field_size);
    }

    for (int k = 0; k < 4; k++)
    {
        if (g)
        {
            for (int h = 0; h < field_size / 2 + 1; h++)
            {
                int f = 0;
                for (int l = 0; l < field_size; l++)
                    if (t[h][l] == as)
                        f++;
                if (f == field_size - 1)
                    for (int l = 0; l < field_size; l++)
                        if (t[h][l] == ' ')
                        {
                            t[h][l] = s;
                            g = 0;
                        }
                if (!g)
                    break;
            }
            if (g)
            {
                int f = 0;
                for (int l = 0; l < field_size; l++)
                    if (t[l][l] == as)
                        f++;

                if (f == field_size - 1)
                    for (int l = 0; l < field_size; l++)
                        if (t[l][l] == ' ')
                        {
                            t[l][l] = s;
                            g = 0;
                        }
            }
        }
        turn(t, field_size);
    }

    if (g)
    {
        int l = rand() % field_size;
        int h = rand() % field_size;

        while (t[h][l] != ' ')
        {
            l = rand() % field_size;
            h = rand() % field_size;
        }
        t[h][l] = s;
    }

    for (i = 0; i < field_size; i++)
        for (j = 0; j < field_size; j++)
            if (t[i][j] != bf[i][j])
                return i * field_size + j;

    return i * field_size + j;
}

void turn(char t[5][5], int sz)
{
    for (int i = 0; i < sz; i++)
        for (int j = i; j < sz; j++)
        {
            char tmp = t[i][j];
            t[i][j] = t[j][i];
            t[j][i] = tmp;
        }
        
    for (int i = 0; i < sz; i++)
        for (int j = 0; j < sz / 2; j++)
        {
            char tmp = t[i][j];
            t[i][j] = t[i][sz - j - 1];
            t[i][sz - j - 1] = tmp;
        }
}
