/*
** EPITECH PROJECT, 2024
** is_ld.c
** File description:
** function for verify if its ld
*/

#include "my.h"

bool is_lld(char **argv, FILE *bin)
{
    if (argv[1] == NULL || argv[2] == NULL || (my_strcmp("lld", argv[0])))
        return false;
    if (find_array_len(argv) == 3
        && (is_direct(argv[1]) || is_indirect(argv[1]))
        && is_register(argv[2])) {
        write_lld(argv, bin);
        return true;
    }
    return false;
}
