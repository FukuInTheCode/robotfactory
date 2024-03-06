/*
** EPITECH PROJECT, 2024
** count_live.c
** File description:
** count_live.c
*/

#include "my.h"

int count_sti(char **argv)
{
    int count = 5;

    if (my_strcmp("sti", *argv) || !argv[1] || !argv[2] || !argv[3])
        return 0;
    count += is_direct(argv[2]);
    count += is_direct(argv[3]);
    return count;
}
