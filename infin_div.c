/*
** EPITECH PROJECT, 2020
** infin_div
** File description:
** infini division
*/

/* Transform int lenstr => char *lentstr and all return (=> infini_add) */

char *remove_zero_sub(char *str1, char *str2);
char *lenstr(char *str1, char *str2); /* add */
char *remove_zero_mult(char *str1, char *str2); /* mult */
char *lenstr_sub(char *str1, char *str2);
int my_strlen(char const *str);
char *my_revstr(char *str);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
/*
prototypes :
// infin_add
infin_sub
//infin_mult
//my_strlen
*/

#include <stdio.h>
#include <stdlib.h>

int lenstr_div(char *str1, char *str2)
{
    int lenstr1 = my_strlen(str1);
    int lenstr2 = my_strlen(str2);
    int i = 0;

    if (lenstr1 > lenstr2)
        return (1);
    if (lenstr2 > lenstr1)
        return (0);
    
    while (str1[i] != '\0' && str2[i] != '\0') {
        if ((str1[i] - '0') > (str2[i] - '0'))
            return (1);
        if ((str2[i] - '0') > (str1[i] - '0'))
            return (0);
        i++;
    }
    return (2);
}

int remove_zero_div(char *str1, char *str2)
{
    while (str1[0] == '0' && str1[1] != '\0') {
        for (int i = 0; str1[i] != '\0' ; i++) {
            str1[i] = str1[i + 1];
        }
    }
    while (str2[0] == '0' && str2[1] != '\0') {
        for (int i = 0; str2[i] != '\0' ; i++) {
            str2[i] = str2[i + 1];
        }
    }
    return (lenstr_div(str1, str2));
}


char *division_cpy(char *dividende, char *diviser)
{
    char *dividende_cpy = malloc(sizeof(char) * my_strlen(dividende) + 10);
    int i = 0;
    int y = 0;

    while (y == 0) {
        dividende_cpy = my_strncpy(dividende_cpy, dividende, i);
        y = lenstr_div(dividende_cpy, diviser);
        i++;
    }
    return (dividende_cpy);
}

char *division(char *dividende, char *diviser)
{
    char *result = malloc(sizeof(char) * my_strlen(dividende) + 2);
    char *factor = malloc(sizeof(char) * my_strlen(dividende) + 2);
    char one[] = "1";
    int i = 0;

    factor[0] = '1';
    while (1) {
        result = remove_zero_mult(diviser, factor);
        i = lenstr_div(result, division_cpy(dividende, diviser));
        if (i == 1) {
            factor = lenstr_sub(factor, one);
            break;
        }
        if (i == 2) {
            break;
        }
        factor = lenstr(factor, one);
    }    
    return factor;
}

char *cut_mult(char *dividende, char *diviser)
{
    char *dividende_cpy;
    char *quotient = malloc(sizeof(char) * 30);
//    char *factor = malloc(sizeof(char) * 30);
    char *reste = (char *)malloc(sizeof(char) * 30);
    int i = 1;
    char *little_quotient = malloc(sizeof(char) * 2);
//    int len = 0;
    int a = 0;
    int y = 0;
    
    while ((lenstr_div(dividende, diviser) > 0) /*|| (i+1 <= my_strlen(diviser))*/) {
        printf("%d\n", my_strlen(diviser));
        
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("div cpy %s\n", dividende_cpy);
        printf("div %s\n", dividende);
        printf("i %d\n", i);
        
        dividende_cpy = malloc(sizeof(char) * my_strlen(dividende) + 2);
        dividende_cpy = my_strncpy(dividende_cpy, dividende, i);
        printf("\ndividende_cpy %s\n\n", dividende_cpy);
//        dividende_cpydividende_cpy
/*        if (dividende_cpy[0] == '0' && dividende_cpy[1] == '0') {
            dividende = dividende + i;
            dividende_cpy = my_strncpy(dividende_cpy, dividende, 1);
            
            printf("UwU\n");
        }*/
            
        if (remove_zero_div(dividende_cpy, diviser) > 0) {
            y = 1;
            quotient = my_strcat(quotient, division(dividende_cpy, diviser));
            little_quotient = division(dividende_cpy, diviser);
//            printf("quotient %s\n\n", quotient);
            printf("little quotient %s\n", little_quotient);
//            printf("%s\n", lenstr_sub(dividende_cpy, remove_zero_mult(quotient, diviser)));
            
            printf("dividende cpy bef rest %s\n", dividende_cpy);
//            printf("quotient bef rest %s\n", quotient);
            printf("diviser bef rest %s\n\n", diviser);


            reste = remove_zero_sub(dividende_cpy, remove_zero_mult(little_quotient, diviser));

            
/*PROBLEME A REGLER AVEC LE REVSTR DANS SUB*/

            printf("reste %s\n", reste);
            
//            dividende = dividende + i;
            if (reste[0] > '0') {
                dividende = my_strcat(reste, dividende + i);
                i = 1;
            }
            else {
                dividende = dividende + i;
                printf("reste null  \n");
                i = 0;
            }
            //          printf("dividende %s\n", dividende);
            
        } else if (y == 1){
            quotient = my_strcat(quotient, "0");
            printf("quotient else %s\n", quotient);
            if (dividende[0] == '0') {
                dividende = dividende + 1;
                i = 0;
                printf("reset i\n");
            }
        }
        free(dividende_cpy);
        i++;
        printf("valeur i %d\n", i);
    }
    return (quotient);
}

int main(void)
{
    char str1[] = "50110";
    char str2[] = "5";
    int i = 0;

    //printf("a %s\n", my_strncpy(str1, str2, i));
    printf("a %s\n", cut_mult(str1, str2));    
}

