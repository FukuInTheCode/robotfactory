/*
** EPITECH PROJECT, 2024
** count_live.c
** File description:
** count_live.c
*/

#include "my.h"

int count_live(char **argv)
{
    if (my_strcmp("live", *argv))
        return 0;
    return 5;
}
