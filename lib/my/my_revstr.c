/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverse a string
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j;
    char temp;

    while (str[i] != '\0') {
        i++;
    }
    j = i -1;
    i = 0;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;;
    }
    return (str);
}
