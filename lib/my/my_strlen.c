/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** 
*/

#include <unistd.h>

int my_putchar(char c);

int my_strlen(char const *str)
{
    int i;
    char nbr = 0;

    i = 0;
    while (str[i] != '\0') {
        i++;
        nbr++;
    }
    return (nbr);
}
