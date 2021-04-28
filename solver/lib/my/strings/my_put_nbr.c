/*
** EPITECH PROJECT, 2020
** Day03
** File description:
** my_put_nbr.c
*/

#include <unistd.h>

int my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        if (write(1, "-2147483648", 11) == -1)
            return (-1);
        return (0);
    }
    if (nb < 0) {
        nb = -nb;
        if (write(1, "-", 1) == -1)
            return (-1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    else
        my_putchar(nb + '0');
    return (0);
}
