/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** idk
*/

int my_strlen_strncmp(char const *str)
{
    int len = 0;

    while (str[0] != '\0') {
        str++;
        len++;
    }
    return len;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int len = my_strlen_strncmp(s1);
    int i = 0;

    while (i < len && i < n) {
        if (s1[i] == '\0' || s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
        i++;
    }
    return 0;
}
