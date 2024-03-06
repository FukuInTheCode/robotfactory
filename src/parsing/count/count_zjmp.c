/*
** EPITECH PROJECT, 2024
** count_live.c
** File description:
** count_live.c
*/

#include "my.h"

int count_zjmp(char **argv)
{
    if (my_strcmp("zjmp", *argv))
        return 0;
    return 3;
}
