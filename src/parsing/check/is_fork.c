/*
** EPITECH PROJECT, 2024
** is_fork.c
** File description:
** function for verify if its fork
*/

#include "my.h"

bool is_fork(char **argv, FILE *bin)
{
    if (my_strcmp(argv[0], "fork") != 0)
        return false;
    if (find_array_len(argv) == 2 && is_direct(argv[1])) {
        write_fork(argv, bin);
        return true;
    }
    return false;
}
