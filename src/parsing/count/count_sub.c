/*
** EPITECH PROJECT, 2024
** count_live.c
** File description:
** count_live.c
*/

#include "my.h"

int count_sub(char **argv)
{
    if (my_strcmp("sub", *argv))
        return 0;
    return 5;
}
