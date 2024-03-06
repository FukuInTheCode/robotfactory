/*
** EPITECH PROJECT, 2024
** is_ldi.c
** File description:
** function for verify if its ldi
*/

#include "my.h"

bool is_ldi(char **argv, FILE *bin)
{
    if (my_strcmp(argv[0], "ldi") != 0)
        return false;
    if (find_array_len(argv) == 4
        && (is_direct(argv[1]) || is_register(argv[1]))
        && (is_direct(argv[2]) || is_register(argv[2]))
        && is_register(argv[3])) {
        write_ldi(argv, bin);
        return true;
    }
    return false;
}
