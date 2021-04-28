/*
** EPITECH PROJECT, 2021
** Dante_heap_malloc_upgrade
** File description:
** path_finding
*/

#include "solver.h"

int heur(path_node cur, path_node target)
{
    sfVector2i start = cur.p;
    sfVector2i stop = target.p;
    int x_dst = abs(start.x - stop.x);
    int y_dst = abs(start.y - stop.y);

    if (x_dst > y_dst)
        return (14 * y_dst + 10 * (x_dst - y_dst));
    return (14 * x_dst + 10 * (y_dst - x_dst));
}

a_star *initialise_struct_astar(st_global *g, sfVector2i pos_start,
sfVector2i target)
{
    a_star *astar = malloc(sizeof(*astar));

    astar->cur = malloc(sizeof(*astar->cur));
    astar->cur->n.parent = malloc(sizeof(*astar->cur->n.parent));
    astar->map = convert_map_to_node(g, pos_start);
    astar->start = astar->map[pos_start.y][pos_start.x]->n;
    astar->target = astar->map[target.y][target.x]->n;
    astar->start.p = pos_start;
    astar->closed = init_hash(g->width, g->height);
    astar->h = init_heap(g);
    astar->max = cantor_pairing(g->width, g->height);
    astar->n = NULL;
    astar->new_move = 0;
    return (astar);
}

void jean_eude(a_star *a)
{
    if (!heap_contains(a->h, a->n->node))
        add_heap(a->h, a->n->node, a->cur);
}

void path_statement(a_star *a)
{
    if (a->n->node->n.bObstacle == false && is_in_hash(a->closed,
    cantor_pairing(a->n->node->n.p.x, a->n->node->n.
    p.y), a->max) == 0) {
        a->new_move = a->map[a->cur->n.p.y][a->cur->n.p.x]->n.g_cost +
        heur(a->cur->n, a->n->node->n);
        if (a->new_move <= a->n->node->n.g_cost
        || !heap_contains(a->h, a->n->node)) {
            a->map[a->n->node->n.p.y][a->n->node->n.p.x]->n.g_cost =
            a->new_move;
            a->map[a->n->node->n.p.y][a->n->node->n.p.x]->n.h_cost =
            heur(a->map[a->n->node->n.p.y][a->n->node->n.p.x]->n, a->target);
            a->map[a->n->node->n.p.y][a->n->node->n.p.x]->n.f_cost = a->new_move
            + a->map[a->n->node->n.p.y][a->n->node->n.p.x]->n.h_cost;
            a->map[a->n->node->n.p.y][a->n->node->n.p.x]->n.parent = \
            copy_node(a->map[a->cur->n.p.y][a->cur->n.p.x]);
            jean_eude(a);
        }
    }
}

int path_finding(st_global *g, sfVector2i pos_start, sfVector2i target)
{
    a_star *a = initialise_struct_astar(g, pos_start, target);

    a->start.f_cost = 0 + heur(a->start, a->target);
    add_heap(a->h, a->map[a->start.p.y][a->start.p.x],
    NULL);
    while (count_heap(a->h) > 0) {
        a->cur = remove_first(a->h);
        insert(a->closed, (sfVector2i){a->cur->n.p.x, a->cur->n.p.y}, a->max);
        if (a->cur->n.p.x == a->target.p.x && a->cur->n.p.y == a->target.p.y)
            break ;
        pop_all_list_n(a->n);
        a->n = get_neighbor(a->map[a->cur->n.p.y][a->cur->n.p.x], g, a->map);
        while (a->n != NULL) {
            path_statement(a);
            a->n = a->n->next;
        }
    }
    return (compute_path(a, g));
}