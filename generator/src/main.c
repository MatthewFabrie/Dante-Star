/*
** EPITECH PROJECT, 2021
** Dante_star
** File description:
** main
*/

#include "../include/strings.h"

int **create(int **temp, map_t *all)
{
    for (int y = 0; y < all->height; y++) {
        for (int x = 0; x < all->width; x++) {
            temp = my_short(temp, x, y, all);
        }
    }
    return (temp);
}

int error_handling(int argc, char **argv)
{
    if (argc != 3 && argc != 4)
        exit(84);
    if (argc == 4 && strcmp(argv[3], "perfect") != 0)
        exit(84);
    return (0);
}

map_t *ini(char **argv)
{
    map_t *all = malloc(sizeof(map_t));

    all->width = atoi(argv[1]);
    all->height = atoi(argv[2]);
    return (all);
}

void my_print(int **temp, int i, int j)
{
    if (temp[i][j] == 1)
        printf("*");
    if (temp[i][j] == 0)
        printf("X");
}

int main(int argc, char **argv)
{
    map_t *all;
    int **temp;

    error_handling(argc, argv);
    all = ini(argv);
    temp = malloc(sizeof(int *) * (all->height));
    for (int i = 0; i < all->height; i++)
        temp[i] = malloc(sizeof(int) * all->width);
    temp = create(temp, all);
    temp = generate(all, temp);
    if (argc == 3)
        temp = generate_imp(all, temp);
    for (int i = 0; i < all->height; i++) {
        for (int j = 0; j < all->width; j++)
            my_print(temp, i, j);
        if (i < all->height - 1)
            printf("\n");
    }
    return (0);
}