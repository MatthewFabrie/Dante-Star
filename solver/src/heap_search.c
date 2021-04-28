/*
** EPITECH PROJECT, 2021
** Dante_heap_malloc_upgrade
** File description:
** heap_search
*/

#include "solver.h"

int sort_down_content(heap *h, heap_node *node)
{
    int childleftindex = (h->heap[node->index]->index * 2) + 1;
    int childrightindex = (h->heap[node->index]->index * 2) + 2;
    int swapindex = 0;

    if (childleftindex < h->nb) {
        swapindex = childleftindex;
        if (childrightindex < h->nb) {
            swap(h, swapindex, childrightindex, childleftindex);
        }
        if (node_compare(node->n, h->heap[swapindex]->n) > 0)
            swap_heap(h, h->heap[node->index], h->heap[swapindex]);
        else
            return (1);
    }
    else
        return (1);
    return (0);
}

void sort_down(heap *h, heap_node *node)
{
    while (true) {
        if (sort_down_content(h, node) == 1)
            return ;
    }
}

bool is_parent_exist(heap_node *node)
{
    if (node->index == 0)
        return (false);
    return (true);
}

void sort_up(heap *h, heap_node *node)
{
    int p_index = 0;
    heap_node *parent = NULL;

    if (!is_parent_exist(node))
        return;
    p_index = (h->heap[node->index]->index - 1) / 2;
    while (true) {
        parent = copy_node(h->heap[p_index]);
        parent->index = p_index;
        if (node_compare(node->n, parent->n) > 0)
            swap_heap(h, node, parent);
        else
            break;
        p_index = (h->heap[node->index]->index - 1) / 2;
    }
}

bool heap_contains(heap *h, heap_node *node)
{
    if (node->index >= h->nb || node->index < 0)
        return (false);
    if (node->n.p.x == h->heap[node->index]->n.p.x &&
    node->n.p.y == h->heap[node->index]->n.p.y)
        return (true);
    return (false);
}