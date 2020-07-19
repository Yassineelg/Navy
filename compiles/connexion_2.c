/*
** EPITECH PROJECT, 2020
** connexion_2
** File description:
** connexion_2.c
*/

#include "my.h"

void successfuly_connected(void)
{
    int fd = 0;

    fd = open("connexion", O_WRONLY);
    write (fd, "yes", 3);
    close (fd);
    my_putstr("successfully connected\n\n");
}

int connexion_part_for_sp(char **av)
{
    char *fp_pid = NULL;

    fp_pid = my_strcpy(fp_pid, connexion_sp());
    if (my_strcmp(fp_pid, av[1])) successfuly_connected();
    else {
        write(2, "failed to connect\n", 19);
        return (84);
    } return (0);
}

void reset_files(void)
{
    int fd = 0;

    fd = open("connexion", O_WRONLY);
    write(fd, "no", 2);
    close(fd);
    fd = open("pid", O_WRONLY);
    write(fd, "0", 1);
    close(fd);
}