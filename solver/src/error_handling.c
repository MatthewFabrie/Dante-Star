/*
** EPITECH PROJECT, 2021
** Dante_heap_malloc_upgrade
** File description:
** error_handling
*/

#include "solver.h"

int check_char(st_global *g, char **map, int i)
{
    for (int j = 0; j < g->width; j++) {
        if (map[i][j] != 'X' && map[i][j] != '*')
            return (84);
    }
    return (0);
}

int error_handling(st_global *g, char **map)
{
    for (int i = 0; i < g->height; i++)
        if (my_strlen(map[i]) > g->width)
            return (84);
    for (int i = 0; i < g->height; i++) {
        if (check_char(g, map, i) == 84)
            return (84);
    }
    return (0);
}

void is_obstacle(char c, int i, int j, heap_node ***tab_node)
{
    if (c == 'X')
        tab_node[i][j]->n.bObstacle = true;
}