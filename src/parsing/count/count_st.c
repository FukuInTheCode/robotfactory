/*
** EPITECH PROJECT, 2024
** count_live.c
** File description:
** count_live.c
*/

#include "my.h"

int count_st(char **argv)
{
    int count = 4;

    if (my_strcmp("st", *argv))
        return 0;
    if (argv[1] && argv[2])
        count += is_indirect(argv[2]);
    return count;
}
