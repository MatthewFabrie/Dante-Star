/*
** EPITECH PROJECT, 2021
** Dante_star
** File description:
** main
*/

#include "../include/strings.h"

void soshort(int x, int i, int j, int **temp)
{
    if (x == 3 && temp[i][j] == 0)
        temp[i][j] = 1;
}

void tooshort(int **temp, int x, int i, int j)
{
    if (i > 0 && j > 0)
        cutter(temp, x, i, j);
    else if (i > 0 && j == 0)
        temp[j][i - 1] = 1;
    else
        temp[j - 1][i] = 1;
}