/*
** EPITECH PROJECT, 2021
** Dante_star
** File description:
** main
*/

#include "solver.h"

char *read_file(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat st;
    int size = 0;
    char *buff;

    if (fd == -1)
        exit(84);
    if (stat(path, &st) == -1)
        exit(84);
    size = st.st_size + 1;
    buff = malloc(sizeof(char) * size);
    if (buff == NULL)
        exit(84);
    if (read(fd, buff, size) == -1)
        exit(84);
    if ((close(fd) == -1) || (size <= 1))
        exit(84);
    buff[size - 1] = 0;
    return (buff);
}

int compute_height_map(char *buff)
{
    int i = 0;
    int count = 0;

    while (buff[i] != '\0') {
        if (buff[i] == '\n')
            count++;
        i++;
    }
    return (count + 1);
}

st_global *ini(char *path)
{
    char *buf = read_file(path);
    st_global *g = malloc(sizeof(*g));
    int i = 0;

    g->map = my_str_to_word_array(buf, "\n");
    for (; g->map[0][i] != '\0';)
        i++;
    g->width = i;
    g->height = compute_height_map(buf);
    return (g);
}

int main(int argc, char **argv)
{
    int res = 0;
    st_global *g = ini(argv[1]);

    if (argc != 2)
        return (84);
    res = error_handling(g, g->map);
    if (res == 84)
        return (res);
    res = path_finding(g, (sfVector2i){0, 0}, (sfVector2i){g->width - 1,
    g->height - 1});
    free(g->map);
    free(g);
    return (res);
}