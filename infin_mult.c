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

char *add_for_mult(char const *str1, char const *str2)
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
    return result;
}

char *lenstr_mult(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    char *result;
    
    if (len1 > len2) {
        result = complete(len1, len2, str2);
        result = add_for_mult(my_revstr(str1), my_revstr(result));
        return result;
    }
    if (len2 > len1) {
        result = complete(len2, len1, str1);
        result = add_for_mult(my_revstr(str2), my_revstr(result));
        return result;
    }
    if (len1 == len2) {
        result = add_for_mult(my_revstr(str1), my_revstr(str2));
        return (result);
    }
}

char *reset_var(char *value)
{
    for (int i = 0; value[i] != '\0'; i++) {
        value[i] = '0';
    }
    return (value);
}

char *inf_mult(char const *str1, char const *str2)
{
    int len = my_strlen(str1) + my_strlen(str2);
    char *result = malloc(sizeof(char) * len + 1);
    int value;
    int  i_str1 = 0;
    char *result_i = malloc(sizeof(char) * len + 1);

    for (int i_str2 = 0; str2[i_str2] != '\0'; i_str2++) {
        value = 0;
        i_str1 = 0;
        result_i = reset_var(result_i);
        while (str1[i_str1] != '\0') {
            value = (str1[i_str1] - '0') * (str2[i_str2] - '0') + value;
            result_i[i_str1 + i_str2] = (value % 10) + '0';
            value = value / 10;
            i_str1++;            
        }
        if (value != 0)
            result_i[i_str1 + i_str2] = value + '0';
        result = lenstr_mult(result, my_revstr(result_i));
    }
    return (result);
}

char *remove_zero_mult(char *str1,char *str2)
{
    int len = my_strlen(str1) + my_strlen(str2);
    char *str_mult = malloc(sizeof(char) * len +2);

    str_mult = inf_mult(my_revstr(str1), my_revstr(str2));
    while (str_mult[0] == '0' && str_mult[1] != '\0') {
        for (int i = 0; str_mult[i] != '\0'; i++) {
            str_mult[i] = str_mult[i + 1];
        }
    }
    str1 = my_revstr(str1);
    str2 = my_revstr(str2);
    return (str_mult);
}
/*
int main(void)
{
    char str1[] = "1";
    char str2[] = "00";
    int i = 0;

    //printf("a %s\n", my_strncpy(str1, str2, i));
    printf("a %s\n", remove_zero_mult(str1, str2));
}  
*/
