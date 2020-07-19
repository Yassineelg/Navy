/*
** EPITECH PROJECT, 2020
** main
** File description:
** main.c
*/

#include "my.h"

void map_player_creation(my_t *nav, char *pos)
{
    int fd = 0;
    char buffer[4096];
    char **all_pos;

    fd = open(pos, O_RDONLY);
    read(fd, buffer, 31);
    close (fd);
    all_pos = my_str_to_word_array(buffer, '\n');
}

void map_creation(my_t *nav)
{
    int fd = 0;
    char buffer[4096];

    fd = open("map", O_RDONLY);
    read(fd, buffer, 179);
    nav->map = malloc(sizeof(char *) * 11);
    for (int i = 0; nav->map[i] && nav->map; i++)
        nav->map[i] = malloc(sizeof(char) * 18);
    nav->map = my_str_to_word_array(buffer, '\n');
}

int game_first_player(my_t *nav, char **av)
{
    size_t len = 1;
    ssize_t size = 0;
    char *buffer = NULL;

    if (errors_handling(av[1]) == 84) return (84);
    my_printf("my_pid: %d\n", getpid());
    connexion_part_for_fp();
    reset_files();
    map_creation(nav);
    map_player_creation(nav, av[1]);
    my_putstr("my positions:\n");
    for (int i = 0; nav->map[i] && nav->map; i++)
        my_printf("%s\n", nav->map[i]);
    my_putstr("\nenemy's positions:\n");
    for (int i = 0; nav->map[i] && nav->map; i++)
        my_printf("%s\n", nav->map[i]);
    my_putstr("\nattack: \033[3m");
    size = getline(&buffer, &len, stdin);
    if (size == -1) return (84);
    return (0);
}

int game_second_player(my_t *nav, char **av)
{
    if (errors_handling(av[2]) == 84) return (84);
    my_printf("my_pid: %d\n", getpid());
    if (connexion_part_for_sp(av) == 84) return (84);
    map_creation(nav);
    map_player_creation(nav, av[1]);
    my_putstr("my positions:\n");
    for (int i = 0; nav->map[i] && nav->map; i++)
        my_printf("%s\n", nav->map[i]);
    my_putstr("\nenemy's positions:\n");
    for (int i = 0; nav->map[i] && nav->map; i++)
        my_printf("%s\n", nav->map[i]);
    my_putstr("\nwaiting for enemy's attack...\n");
    while (1);
    return (0);
}

int main(int ac, char **av)
{
    my_t *nav = malloc(sizeof(my_t));

    if (ac == 2 && my_strcmp(av[1], "-h")) {
        tiret_h();
        return (0);
    } if (ac == 2 && !my_strcmp(av[1], "-h")) {
        if (game_first_player(nav, av) == 84) return (84);
    } else if (ac == 3) {
        if (game_second_player(nav, av) == 84) return (84);
    } else return (84);
    reset_files();
    return (0);
}