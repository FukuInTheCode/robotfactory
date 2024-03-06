/*
** EPITECH PROJECT, 2024
** is_zjmp.c
** File description:
** function for verify if its zjmp
*/

#include "my.h"

bool is_zjmp(char **argv, FILE *bin)
{
    if (my_strcmp("zjmp", argv[0]) != 0)
        return false;
    if (find_array_len(argv) == 2 && is_direct(argv[1])) {
        write_zjmp(argv, bin);
        return true;
    }
    return false;
}
