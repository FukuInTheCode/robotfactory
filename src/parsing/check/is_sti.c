/*
** EPITECH PROJECT, 2024
** is_sti.c
** File description:
** verify if it's a sti
*/

#include "my.h"

bool is_sti(char **argv, FILE *bin)
{
    if (my_strcmp(argv[0], "sti") != 0)
        return false;
    if (find_array_len(argv) == 4 && is_register(argv[1])
        && (is_register(argv[2]) || is_direct(argv[2]))
        && (is_register(argv[3]) || is_direct(argv[3]))) {
        write_sti(argv, bin);
        return true;
    }
    return false;
}