/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** idk
*/

char *my_strcat(char *dest, char const *src)
{
    {
        int i = 0;
        int j = 0;

        while (dest[i] != '\0') {
            dest[i] = dest[i];
            i++;
        }
        while (src[j] != '\0') {
            dest[i] = src[j];
            i++;
            j++;
        }
        dest[i]  = '\0';
        return dest;
    }
}
