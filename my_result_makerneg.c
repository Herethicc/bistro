/*
** EPITECH PROJECT, 2020
** make the result pos or neg
** File description:
** initially made for sub
*/

#include <stdlib.h>

char *my_result_maker(char *result, int neg)
{
    char *final_res = "";
    int i = 0;

    final_res = malloc(sizeof(char) * my_strlen(result) + 2);
    result = my_revstr(result);
    if (neg == 1) {
        final_res[0] = '-';
        for (; result[i] != '\0'; i++) {
            final_res[i + 1] = result[i];
        }
    } else {
        return (result);
    }
    final_res[i + 1] = '\0';
    return (final_res);
}
