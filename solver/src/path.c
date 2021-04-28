/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** path
*/

#include "solver.h"

list_n get_neighbor(heap_node *cur, st_global *global, heap_node
***map_nodes)
{
    list_n list = NULL;

    if (cur->n.p.y > 0)
        list = push_back_list_n(list, map_nodes[cur->n.p.y - 1][\
        cur->n.p.x] , cur);
    if (cur->n.p.y < global->height - 1)
        list = push_back_list_n(list, map_nodes[cur->n.p.y + 1]\
        [cur->n.p.x], cur);
    if (cur->n.p.x > 0)
        list = push_back_list_n(list, map_nodes[cur->n.p.y]\
        [cur->n.p.x - 1], cur);
    if (cur->n.p.x < global->width - 1)
        list = push_back_list_n(list, map_nodes[cur->n.p.y]\
        [cur->n.p.x + 1], cur);
    return (list);
}

int heur_by_pos(sfVector2i start, sfVector2i stop)
{
    int x_dst = abs(start.x - stop.x);
    int y_dst = abs(start.y - stop.y);

    if (x_dst > y_dst)
        return (14 * y_dst + 10 * (x_dst - y_dst));
    return (14 * x_dst + 10 * (y_dst - x_dst));
}

heap_node ***convert_map_to_node(st_global *global, sfVector2i start)
{
    heap_node ***tab_node = malloc(sizeof(heap_node **) * global->height);

    for (int i = 0; i < global->height; i++) {
        tab_node[i] = malloc(sizeof(heap_node *) * global->width);
        for (int j = 0; j < global->width; j++) {
            tab_node[i][j] = malloc(sizeof(heap_node));
            tab_node[i][j]->index = -10;
            tab_node[i][j]->n.p.x = j;
            tab_node[i][j]->n.p.y = i;
            tab_node[i][j]->n.h_cost = 999;
            tab_node[i][j]->n.g_cost = heur_by_pos((sfVector2i){j, i}, start);
            tab_node[i][j]->n.f_cost = 999;
            tab_node[i][j]->n.bVisited = false;
            tab_node[i][j]->n.bObstacle = false;
            tab_node[i][j]->n.start = start;
            is_obstacle(global->map[i][j], i, j, tab_node);
            tab_node[i][j]->n.parent = NULL;
        }
    }
    return (tab_node);
}

int print_path(st_global *global, a_star *astar)
{
    if (global->map[global->height - 1][global->width - 1] != 'o') {
        printf("no solution found\n");
        free(astar->cur);
        free(astar);
        astar = NULL;
        return (84);
    }
    for (int i = 0; i < global->height; i++) {
        printf("%s", global->map[i]);
        if (i != global->height - 1)
            printf("\n");
    }
    free(astar->cur);
    free(astar);
    astar = NULL;
    return (0);
}

int compute_path(a_star *astar, st_global *global)
{
    list_astar path = NULL;

    while (astar->cur != NULL) {
        global->map[astar->cur->n.p.y][astar->cur->n.p.x] = 'o';
        path = push_front_list_astar(path, astar->cur, \
        astar->cur->n.parent);
        astar->cur = astar->cur->n.parent;
    }
    return (print_path(global, astar));
}