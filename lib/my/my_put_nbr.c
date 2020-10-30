/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** put a number
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int mod;

    if (-2147483647 > nb || 2147483647 < nb)
        return 0;
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    mod = nb % 10;
    nb = nb / 10;
    if (nb > 0)
        my_put_nbr(nb);
    my_putchar(mod + 48);
}
