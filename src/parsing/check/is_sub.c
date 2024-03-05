/*
** EPITECH PROJECT, 2024
** is_sub.c
** File description:
** function for verify if its sub
*/

#include "my.h"

bool is_add(char **argv, FILE *bin)
{
    if (find_array_len(argv) != 4 || argv[1] == NULL
        || argv[2] == NULL || argv[3] == NULL)
        return false;
    if (my_strcmp(argv[0], "sub") == 0 && is_register(argv[1])
        && is_register(argv[2]) && is_register(argv[3])) {
        write_sub(argv, bin);
        return true;
    }
    return false;
}
