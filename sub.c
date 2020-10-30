/*
** EPITECH PROJECT, 2020
** sub
** File description:
** sub
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>

int lenstr(char *str1, char *str2);
char *my_result_maker(char *result, int neg);

char *inf_sub(char *str1, char const *str2, int neg)
{
    char *result = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    int stock = 0;
    int i = 0;
    int value;

    for (; str1[i] != '\0'; i++) {
        if (str1[i] < str2[i]) {
            stock = 10;
            str1[i + 1] = (((str1[i + 1] - '0') - 1)  + '0');
        }
        value = ((str1[i] - '0') + stock) - (str2[i] - '0');
        result[i] = (value) + '0';
        stock = 0;
    }
    if (result[i - 1] == '0')
        result[i - 1] = '\0';
    result = my_result_maker(result, neg);
    return (result);
}

char *complete(int talStr, int litStr, char const *strLit)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * talStr + 1);

    while (talStr > litStr) {
        dest[i] = '0';
        i++;
        talStr--;
    }
    dest = my_strcat(dest, strLit);
    return dest;
}

char *my_strcmp_sub(char *str1, char *str2)
{
    int i = 0;
    char *res = "";

    while (str1[i] != '\0') {
        if (str1[i] < str2[i]) {
            res = inf_sub(my_revstr(str2), my_revstr(str1), 1);
            return (res);
        }
        if (str1[i] > str2[i]) {
            res = inf_sub(my_revstr(str1), my_revstr(str2), 2);
            return (res);
        }
        return "0";
    }
}

char *lenstr_sub(char *str1, char *str2)
{
    int lenstr1 = my_strlen(str1);
    int lenstr2 = my_strlen(str2);
    char *result = "";
    char *fin_res = "";

    if (lenstr1 > lenstr2) {
        result = complete(lenstr1, lenstr2, str2);
        fin_res = inf_sub(my_revstr(str1), my_revstr(result), 2);
    }
    if (lenstr2 > lenstr1) {
        result = complete(lenstr2, lenstr1, str1);
        fin_res = inf_sub(my_revstr(str2), my_revstr(result), 1);
    }
    if (lenstr1 == lenstr2)
        fin_res = my_strcmp_sub(str1, str2);
    return (fin_res);
}

char *remove_zero_sub(char *str1, char *str2)
{
    char *res = "";
    int neg = 0;
    while (str1[0] == '0' && str1[1] != '\0') {
        for (int i = 0; str1[i] != '\0' ; i++)
            str1[i] = str1[i + 1];
    }
    while (str2[0] == '0' && str2[1] != '\0') {
        for (int i = 0; str2[i] != '\0' ; i++)
            str2[i] = str2[i + 1];
    }
    res = lenstr_sub(str1, str2);
    return res;
}
