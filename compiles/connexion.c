/*
** EPITECH PROJECT, 2020
** connexion
** File description:
** connexion.c
*/

#include "my.h"

int save_pid(void)
{
    int fd = 0;

    fd = open("pid", O_WRONLY);
    write(fd, my_rev_putnbr(getpid()), my_strlen(my_rev_putnbr(getpid())));
    close(fd);
}

int connexion_fp(void)
{
    int fd = 0;
    int len = 0;
    char buffer[4096];
    char *connexion = NULL;

    fd = open("connexion", O_RDONLY);
    read(fd, buffer, 3);
    close (fd);
    if (my_strcmp(buffer, "yes")) return (1);
    else return (0);
}

void reset_connexion(void)
{
    int fd = 0;

    fd = open("connexion", O_WRONLY);
    write (fd, "no", 2);
    close (fd);
}

int connexion_part_for_fp(void)
{
    save_pid();
    my_putstr("waiting for enemy connection...\n\n");
    while (1) {
        usleep(1);
        if (connexion_fp()) break;
    } my_putstr("enemy connected\n");
    reset_connexion();
}

char *connexion_sp(void)
{
    int fd = 0;
    int len = 0;
    char buffer[1];
    char *fp_pid = NULL;

    fd = open("pid", O_RDONLY);
    while (read(fd, buffer, 1)) fp_pid = my_strcat(fp_pid, buffer);
    return (fp_pid);
}