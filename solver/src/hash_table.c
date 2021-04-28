/*
** EPITECH PROJECT, 2021
** Dante_star
** File description:
** hash_table
*/

#include "solver.h"

int cantor_pairing(int a, int b)
{
    return ((a + b) * (a + b + 1) / 2 + a);
}

int hash_code(int key, int max_pairing)
{
    return (key % max_pairing);
}

bool is_in_hash(hash_node *h, int key, int max_pairing)
{
    int hash_index = hash_code(key, max_pairing);

    if (h[hash_index].key == key)
        return (true);
    return (false);
}

void insert(hash_node *h, sfVector2i data, int max_pairing)
{
    hash_node item;
    int key = cantor_pairing(data.x, data.y);
    int hash_index = hash_code(key, max_pairing);

    item.key = key;
    item.node = data;
    h[hash_index] = item;
}

hash_node *init_hash(int max_x, int max_y)
{
    hash_node *h = malloc(sizeof(hash_node *));

    h = malloc(sizeof(hash_node) * cantor_pairing(max_x, max_y));
    return (h);
}