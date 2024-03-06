/*
** EPITECH PROJECT, 2024
** is_aff.c
** File description:
** function for verify if its aff
*/

#include "my.h"

bool is_aff(char **argv, FILE *bin)
{
    if (my_strcmp("aff", argv[0]) != 0)
        return false;
    if (find_array_len(argv) == 2 && is_register(argv[1])) {
        write_aff(argv, bin);
        return true;
    }
    return false;
}
