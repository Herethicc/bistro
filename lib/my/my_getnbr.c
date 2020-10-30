/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** idk
*/

int my_getnbr(char const *str)
{
    int signe = 1;
    int i = 0;
    long result = 0;

    while (str[i] != '\0' && (str[i] <= '0' || str[i] >= '9')) {
        if (str[i] == '-')
            signe = signe * -1;
        if (str[i] > '9' || str[i] < '0' &&  str[i] != '-' && str[i] != '+')
            return 0;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - 48);
        if (-2147483647 > result || 2147483647 < result)
            return 0;
        i++;
    }
    result = result * signe;
    return result;
}
