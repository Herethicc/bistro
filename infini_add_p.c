/*
** EPITECH PROJECT, 2020
** infinit_add_p
** File description:
** add positiv nbr
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);
char *my_revstr(char *str);
char *my_strdup(char const *src);
char *my_strcat(char *dest, char const *src);
int my_putstr(char const *str);
char *complete(int talStr, int litStr, char const *strLit);

char *inf_add(char const *str1, char const *str2)
{
    char *result = malloc(sizeof(char) * (my_strlen(str1) + 4));
    int stock = 0;
    int i = 0;
    int value;

    while (str1[i] != '\0') {
        value = (str1[i] - '0') + (str2[i] - '0') + stock;
        result[i] = (value % 10) + '0';
        stock = value / 10;
        i++;
    }
    if (stock == 1) {
        result[i] = '1';
        i++;
    }
    result[i] = '\0';
    result = my_revstr(result);
    return (result);
}

char *lenstr(char *str1, char *str2)
{
    //printf("str1 et 2 :\n");
    //printf("%s\n", str1);
    //printf("%s\n", str2);
    int lenstr1 = my_strlen(str1);
    int lenstr2 = my_strlen(str2);
    char *result;

    if (lenstr1 > lenstr2) {
        result = complete(lenstr1, lenstr2, str2);
        return (inf_add(my_revstr(str1), my_revstr(result)));
    }
    if (lenstr2 > lenstr1) {
        result = complete(lenstr2, lenstr1, str1);
        return (inf_add(my_revstr(str2), my_revstr(result)));
    }
    if (lenstr1 == lenstr2)
        return (inf_add(my_revstr(str1), my_revstr(str2)));
}
