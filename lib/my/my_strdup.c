/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** allocate memories duplicate copie string
*/

#include <stdlib.h>
#include <stdio.h>

char *my_strcpy(char *dest, char const *src);

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *dest;
    char *str;
    int nbr;
    int i = 0;

    nbr = my_strlen(src);
    str = malloc(sizeof(char) * (nbr + 1));
    dest = my_strcpy(str, src);
    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }
    return str;
}
