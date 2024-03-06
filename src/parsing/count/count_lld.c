/*
** EPITECH PROJECT, 2024
** count_live.c
** File description:
** count_live.c
*/

#include "my.h"

int count_lld(char **argv)
{
    int count = 5;

    if (my_strcmp(*argv, "lld"))
        return 0;
    if (argv[1])
        count += 2 * is_direct(argv[1]);
    return count;
}
