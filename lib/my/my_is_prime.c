/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** idk
*/

int my_is_prime(int nb)
{
    int i = 2;

    if (nb < 2)
        return (0);
    while (i < nb) {
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}
