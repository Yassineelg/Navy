/*
** EPITECH PROJECT, 2020
** errors
** File description:
** errors.c
*/

#include "my.h"

int errors_handling_2(char **map, int y)
{
    if (map[y][3] > '8' || map[y][3] < '1' ||
    map[y][6] > '8' || map[y][6] < '1') return (84);
    if (map[y][2] != map[y][5] && map[y][3] != map[y][6]) return (84);
    if (map[y][2] > map[y][5] && (map[y][2] - map[y][5] + 49) != map[y][0])
        return (84);
    if (map[y][2] < map[y][5] && (map[y][5] - map[y][2] + 49) != map[y][0])
        return (84);
    if (map[y][3] > map[y][6] && (map[y][3] - map[y][6] + 49) != map[y][0])
        return (84);
    if (map[y][3] < map[y][6] && (map[y][6] - map[y][3] + 49) != map[y][0])
        return (84);
}

int errors_handling(char *arg)
{
    int fd = 0;
    int len = 0;
    char **map;
    char buffer[4096];

    fd = open(arg, O_RDONLY);
    if (fd == -1) return (84);
    len = read(fd, buffer, 31);
    if (len == -1) return (84);
    close (fd);
    if (buffer[31] != '\0') return (84);
    map = my_str_to_word_array(buffer, '\n');
    for (int y = 0, x = 0; map[y] && map; y++, x = 0) {
        if (map[y][0] != (y + 2 + '0')) return (84);
        if (map[y + 1] && map[y][8] != '\0') return (84);
        if (map[y][1] != ':' || map[y][4] != ':') return (84);
        if (map[y][2] > 'H' || map[y][2] < 'A' ||
        map[y][5] > 'H' || map[y][5] < 'A') return (84);
        if (errors_handling_2(map, y) == 84) return (84);
    } return (0);
}