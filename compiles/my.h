/*
** EPITECH PROJECT, 2019
** my.h..
** File description:
** all prototypes.
*/

#ifndef MY_H
#define MY_H

#include "../Include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct my_struct_s {
    char **map;
    char **map_player;
} my_t;

void successfuly_connected(void);
int connexion_part_for_sp(char **av);
void reset_files(void);
int save_pid(void);
int connexion_fp(void);
void reset_connexion(void);
int connexion_part_for_fp(void);
char *connexion_sp(void);
int errors_handling(char *arg);
void map_creation(my_t *nav);
void tiret_h(void);

#endif