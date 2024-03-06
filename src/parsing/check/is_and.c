/*
** EPITECH PROJECT, 2024
** is_and.c
** File description:
** function for verify if its and
*/

#include "my.h"

bool is_and(char **argv, FILE *bin)
{
    if (my_strcmp("and", argv[0]) != 0)
        return false;
    if (find_array_len(argv) != 4 || argv[1] == NULL
        || argv[2] == NULL || argv[3] == NULL)
        return false;
    if ((is_direct(argv[1]) || is_indirect(argv[1]) || is_label(argv[1])
        || is_register(argv[1]))
        && (is_direct(argv[2]) || is_indirect(argv[2])
        || is_label(argv[2]) || is_register(argv[2]))
        && (is_register(argv[3]))) {
        write_and(argv, bin);
        return true;
    }
    return false;
}
