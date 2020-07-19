/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>

char **my_str_to_word_array(char *str, char c)
{
    int space = 0;
    int remove = 0;
    char **tab = NULL;

    for (int i = 0; str[i] != '\0'; i++) if (str[i] == c) space++;
    tab = malloc(sizeof(char *) * space + 1);
    for (int j = 0, i = remove + 0; j <= space; j++, i++) {
        for (; str[i] != '\0' && str[i] != c; i++);
        tab[j] = malloc(sizeof(char) * i);
    } for (int i = 0, j = 0, x = remove + 0; i <= space; i++, x++) {
        for (j = 0; str[x] != c && str[x] != '\0'; j++, x++)
            tab[i][j] = str[x];
        tab[i][j] = '\0';
    } tab[space + 1] = NULL;
    return (tab);
}