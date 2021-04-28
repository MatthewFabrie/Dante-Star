/*
** EPITECH PROJECT, 2020
** string
** File description:
** my_putchar_error
*/

#include <unistd.h>

void my_putchar_error(char c)
{
    if (write(2, &c, 1) == - 1)
        return;
}
