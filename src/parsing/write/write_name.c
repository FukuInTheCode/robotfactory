/*
** EPITECH PROJECT, 2024
** write_name.c
** File description:
** write_name.c
*/

#include "my.h"

int write_name(char **argv, FILE *bin)
{
    char name[PROG_NAME_LENGTH];

    for (int i = 0; i < PROG_NAME_LENGTH; i++)
        name[i] = 0;
    my_strcat(name, argv[1]);
    fwrite(&name, sizeof(name), 1, bin);
    return 0;
}
