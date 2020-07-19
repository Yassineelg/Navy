/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** Displays all caracteres one-by-one.
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int lockers = 0;

    if (str != NULL)
        while (str[lockers] != '\0') lockers++;
    return (lockers);
}