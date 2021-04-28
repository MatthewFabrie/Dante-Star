/*
** EPITECH PROJECT, 2021
** Dante_heap_malloc_upgrade
** File description:
** heap_compare
*/

#include "solver.h"

int node_compare_fcost(path_node a, path_node b)
{
    if (a.f_cost < b.f_cost)
        return (-1);
    else if (a.f_cost > b.f_cost)
        return (1);
    else
        return (0);
}

int node_compare_hcost(path_node a, path_node b)
{
    if (a.h_cost < b.h_cost)
        return (-1);
    else if (a.h_cost > b.h_cost)
        return (1);
    else
        return (0);
}

int node_compare(path_node a, path_node b)
{
    int compare = node_compare_fcost(a, b);

    if (compare == 0) {
        compare = node_compare_hcost(a, b);
    }
    return (-compare);
}

heap *init_heap(st_global *g)
{
    heap *h = malloc(sizeof(*h));
    h->heap = malloc(sizeof(*h->heap) * (g->height * g->width));
    h->nb = 0;
    return (h);
}

int swap(heap *h, int swapindex, int right, int left)
{
    if (node_compare(h->heap[left]->n,
    h->heap[right]->n) > 0)
        swapindex = right;
    return (swapindex);
}