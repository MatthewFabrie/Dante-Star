/*
** EPITECH PROJECT, 2021
** Dante_star
** File description:
** main
*/

#include "../include/strings.h"

void cutter(int **temp, int x, int i, int j)
{
    if (x == 1)
        temp[j][i - 1] = 1;
    else
        temp[j - 1][i] = 1;
}

void shorter(int j, map_t *all, int **temp)
{
    int x = 0;

    for (int i = 0; i < all->width; i += 2) {
        x = rand() % 2;
        if (j == 0 && i == 0)
            continue;
        else
            tooshort(temp, x, i, j);
    }
}

int **generate(map_t *all, int **temp)
{
    srand(time(NULL));

    for (int j = 0; j < all->height; j += 2)
        shorter(j, all, temp);
    return (temp);
}

int **generate_imp(map_t *all, int **temp)
{
    srand(time(NULL));
    int x = 0;

    for (int i = 0; i < all->height; i++) {
        for (int j = 0; j < all->width; j++) {
            x = rand() % 6;
            soshort(x, i, j, temp);
        }
    }
    return (temp);
}

int **my_short(int **temp, int x, int y, map_t *all)
{
    if (all->width == 1 || all->height == 1)
        temp[y][x] = 1;
    else if ((x % 2 == 0 && y % 2 == 0) || (((x + 1 == all->width || x + 2 ==
    all->width) && y + 1 == all->height) && all->width % 2 == 0) ||
    (x + 1 == all->width && y + 1 == all->height))
        temp[y][x] = 1;
    else
        temp[y][x] = 0;
    return (temp);
}