/*
** EPITECH PROJECT, 2021
** Dante_star
** File description:
** heap
*/

#include "solver.h"

void add_heap(heap *h, heap_node *node, heap_node *parent)
{
    node->index = h->nb;
    h->heap[h->nb] = malloc(sizeof(*h->heap[h->nb]));
    h->heap[h->nb] = copy_node(node);
    h->heap[h->nb]->n.parent = malloc(sizeof(*h->heap[h->nb]->n.parent));
    h->heap[h->nb]->n.parent = copy_node(parent);
    h->heap[h->nb]->index = h->nb;
    sort_up(h, h->heap[h->nb]);
    h->nb += 1;
}

heap_node *copy_node(heap_node *node)
{
    heap_node *result = malloc(sizeof(*result));
    list_n li_n = malloc(sizeof(*li_n));

    if (node == NULL)
        return (NULL);
    li_n = node->n.neighbours;
    result->n.bObstacle = node->n.bObstacle;
    result->n.bVisited = node->n.bVisited;
    result->n.f_cost = node->n.f_cost;
    result->n.g_cost = node->n.g_cost;
    result->n.h_cost = node->n.h_cost;
    result->index = node->index;
    result->n.parent = malloc(sizeof(path_node *));
    result->n.parent = node->n.parent;
    result->n.p = node->n.p;
    return (result);
}

void swap_heap(heap *h, heap_node *a, heap_node *b)
{
    heap_node *temp = copy_node(a);
    int a_index = h->heap[a->index]->index;
    int b_index = h->heap[b->index]->index;

    h->heap[a->index] = copy_node(b);
    h->heap[a->index]->index = a_index;
    h->heap[b->index] = copy_node(temp);
    h->heap[b->index]->index = b_index;
}

heap_node *remove_first(heap *h)
{
    heap_node *first = NULL;
    first = copy_node(h->heap[0]);
    first->index = 0;

    h->nb -= 1;
    h->heap[0] = copy_node(h->heap[h->nb]);
    h->heap[0]->index = 0;
    sort_down(h, h->heap[0]);
    return (first);
}

int count_heap(heap *h)
{
    return (h->nb);
}