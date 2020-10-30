/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** idk
*/

int my_compute_square_root(int nb)
{
    int square_root = 1;
    int result;

    while (square_root * square_root < nb) {
        square_root++;
    }
    if (square_root * square_root != nb)
        square_root = 0;
    return (square_root);
}
