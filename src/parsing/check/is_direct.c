/*
** EPITECH PROJECT, 2024
** is_direct.c
** File description:
** is_direct.c
*/

#include "my.h"
#include "op.h"

bool is_direct(char const *arg)
{
    if (*arg != DIRECT_CHAR || !arg[1])
        return false;
    for (int i = 1; arg[i]; i++)
        if (!('0' <= arg[i] && arg[i] <= '9'))
            return false;
    return true;
}
