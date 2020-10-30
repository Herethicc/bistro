/*
** EPITECH PROJECT, 2020
** my_getnbr_operator
** File description:
** calculator operator
*/

int my_getnbr_operator(char const *str)
{
    int a = 0;

    if (str[0] == '-')
        a = 1;
    if (str[0] == '+')
        a = 2;
    if (str[0] == '*')
        a = 3;
    if (str[0] == '/')
        a = 4;
    if (str[0] == '%')
        a = 5;
    return a;
}
