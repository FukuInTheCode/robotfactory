/*
** EPITECH PROJECT, 2024
** count_live.c
** File description:
** count_live.c
*/

#include "my.h"

int count_st(char **argv)
{
    int count = 3;

    if (my_strcmp(*argv, "st"))
        return 0;
    if (argv[1])
        count += 2 * is_indirect(argv[1]);
    return count;
}
