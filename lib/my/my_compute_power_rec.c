/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** idk
*/

#include <unistd.h>

int my_putchar(char c);

int my_compute_power_rec(int nb, int p)
{
    int power;

    if (p < 0)
        power = 0;
    else if (p == 0)
        power = 1;
    else {
        power = nb * my_compute_power_rec(nb, p - 1);
    }
    return (power);
}
