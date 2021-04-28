/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** list_astar
*/

#include "solver.h"

list_astar push_front_list_astar(list_astar li, heap_node *node, \
heap_node *parent)
{
    list_elem_astar *elem = malloc(sizeof(*elem));
    list_n li_n = malloc(sizeof(*li_n));

    li_n = node->n.neighbours;
    elem->node = malloc(sizeof(*elem->node));
    elem->node->n.bObstacle = node->n.bObstacle;
    elem->node->n.bVisited = node->n.bVisited;
    elem->node->n.f_cost = node->n.f_cost;
    elem->node->n.g_cost = node->n.g_cost;
    elem->node->n.h_cost = node->n.h_cost;
    elem->node->n.neighbours = NULL;
    elem->node->n.parent = malloc(sizeof(path_node *));
    elem->node->n.parent = copy_node(parent);
    elem->node->n.p = node->n.p;
    elem->node->index = node->index;
    if (li == NULL)
        elem->next = NULL;
    else
        elem->next = li;
    return (elem);
}

list_astar pop_front_astar(list_astar li)
{
    list_elem_astar *elem;

    if (li == NULL)
        return (li);
    elem = malloc(sizeof(*elem));
    elem = li->next;
    free(li);
    li = NULL;
    return (elem);
}

void pop_all_list_astar(list_astar li)
{
    while (li != NULL)
        li = pop_front_astar(li);
}