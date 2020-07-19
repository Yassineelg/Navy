/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenates two strings
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../Include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int compt = 0;
    char *temp = dest;

    dest = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)));
    if (temp != NULL)
        for (int j = 0; temp[j]; j++) dest[j] = temp[j];
    while (dest[compt] != '\0')
        compt++;
    while (src[i] != '\0') {
        dest[compt + i] = src[i];
        i++;
    } dest[compt + i] = '\0';
    return (dest);
}