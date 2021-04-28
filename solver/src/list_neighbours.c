/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** list_neighbours
*/

#include "solver.h"

void cut(list_elem_n *elem, heap_node *node, heap_node *parent)
{
    elem->node = malloc(sizeof(*elem->node));
    elem->node->n.bObstacle = node->n.bObstacle;
    elem->node->n.bVisited = node->n.bVisited;
    elem->node->n.f_cost = node->n.f_cost;
    elem->node->n.p = node->n.p;
    elem->node->n.g_cost = heur_by_pos(elem->node->n.p, parent->n.start);
    elem->node->n.h_cost = node->n.h_cost;
    elem->node->n.neighbours = NULL;
    elem->node->n.parent = malloc(sizeof(path_node *));
    elem->node->n.parent = parent;
    elem->node->index = node->index;
    elem->next = NULL;
}

list_n push_back_list_n(list_n li, heap_node *node, heap_node *parent)
{
    list_elem_n *elem = malloc(sizeof(*elem));
    list_elem_n *temp;
    list_n list = malloc(sizeof(list));

    cut(elem, node, parent);
    if (li == NULL)
        return (elem);
    temp = li;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = elem;
    return (li);
}

list_n pop_back_n(list_n li)
{
    list_elem_n *temp = NULL;
    list_elem_n *buffer = NULL;

    if (li == NULL)
        return (li);
    if (li->next == NULL) {
        free(li);
        li = NULL;
        return (NULL);
    }
    temp = li;
    buffer = li;
    while (temp->next != NULL) {
        buffer = temp;
        temp = temp->next;
    }
    buffer->next = NULL;
    free(temp);
    temp = NULL;
    return (li);
}

void pop_all_list_n(list_n li)
{
    while (li != NULL)
        li = pop_back_n(li);
    free(li);
    li = NULL;
}