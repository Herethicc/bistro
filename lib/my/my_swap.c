/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** idk
*/

#include <unistd.h>

void my_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
}
