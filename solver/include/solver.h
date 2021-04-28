/*
** EPITECH PROJECT, 2021
** header
** File description:
** solver.h
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include "strings.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct sfVector2i_s {
    int x;
    int y;
} sfVector2i;

typedef struct path_node_s path_node;
typedef struct heap_node_s heap_node;

typedef struct list_astar_s {
    heap_node *node;
    struct list_astar *next;
} *list_astar, list_elem_astar;

typedef struct list_neighbours_s
{
    heap_node *node;
    struct list_neighbours *next;
}*list_n, list_elem_n;

typedef struct path_node_s
{
    int f_cost;
    int g_cost;
    int h_cost;
    bool bObstacle;
    bool bVisited;
    list_n neighbours;
    sfVector2i p;
    sfVector2i start;
    heap_node *parent;
} path_node;


typedef struct st_global_s {
    char **map;
    int height;
    int width;
} st_global;

typedef struct heap_node_s
{
    path_node n;
    int index;
} heap_node;

typedef struct heap_s {
    heap_node **heap;
    int nb;
} heap;

typedef struct hash_node_s {
    sfVector2i node;
    int key;
} hash_node;

typedef struct a_star_s {
    heap_node ***map;
    heap_node *cur;
    path_node start;
    path_node target;
    list_astar path;
    list_n n;
    heap *h;
    hash_node *closed;
    int max;
    int new_move;
} a_star;


int error_handling(st_global *g, char **map);
    // LIST_NEIGHBOURS
        list_n push_back_list_n(list_n li, heap_node *node, heap_node *parent);
        int size_list_n(list_n li);
        void pop_all_list_n(list_n li);
    // LIST_ASTAR
        list_astar push_front_list_astar(list_astar li, heap_node *node, \
        heap_node *parent);
        list_astar pop_front_astar(list_astar li);
        void pop_all_list_astar(list_astar li);
    // PATH
        int heur_by_pos(sfVector2i start, sfVector2i stop);
        heap_node ***convert_map_to_node(st_global *global, sfVector2i start);
        int path_finding(st_global *global, sfVector2i pos_start,
        sfVector2i target);
        void generate_path(st_global **global);
        path_node *last_elem_astar(list_astar li);
        list_n get_neighbor(heap_node *cur, st_global *global, heap_node
        ***map_nodes);
        int compute_path(a_star *astar, st_global *global);
        heap *init_heap(st_global *g);
    // HEAP
        void add_heap(heap *h, heap_node *node, heap_node *parent);
        heap_node *copy_node(heap_node *node);
        void free_node(heap_node *n);
        void swap_heap(heap *h, heap_node *a, heap_node *b);
        int node_compare_fcost(path_node a, path_node b);
        int node_compare_hcost(path_node a, path_node b);
        int node_compare(path_node a, path_node b);
        heap_node *remove_first(heap *h);
        int sort_down_content(heap *h, heap_node *node);
        void sort_down(heap *h, heap_node *node);
        void sort_up(heap *h, heap_node *node);
        bool heap_contains(heap *h, heap_node *node);
        int count_heap(heap *h);
        void update_node(heap *h, heap_node *node);
        int swap(heap *h, int swapindex, int right, int left);
        void is_obstacle(char c, int i, int j, heap_node ***tab_node);
    // HASH_SET
        int cantor_pairing(int a, int b);
        bool is_in_hash(hash_node *h, int key, int max_pairing);
        void insert(hash_node *h, sfVector2i data, int max_pairing);
        void display(hash_node *h, int max_pairing);
        hash_node *init_hash(int max_x, int max_y);
#endif /* !SOLVER_H_ */
