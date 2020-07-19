/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** my_strcmp
*/

int my_strcmp(char *str1, char *str2)
{
    int a = 0;
    int j = 0;

    for (; str1[a]; a++);
    for (; str1[j]; j++);
    if (a != j) return (0);
    for (int i = 0; str1[i] && str2[i]; i++)
        if (str1[i] != str2[i]) return (0);
    return (1);
}