/*
** EPITECH PROJECT, 2020
** tiret_h
** File description:
** tiret_h.c
*/

#include "my.h"

void tiret_h(void)
{
    int fd = 0;
    int len = 0;
    char buffer[1];

    fd = open("tiret_h.txt", O_RDONLY);
    while (read(fd, buffer, 1)) my_putstr(buffer);
    my_putchar('\n');
    close(fd);
}