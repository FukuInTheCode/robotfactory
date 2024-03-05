/*
** EPITECH PROJECT, 2024
** is_direct.c
** File description:
** is_direct.c
*/

#include "my.h"
#include "op.h"

bool is_indirect(char const *arg)
{
    if (!arg)
        return false;
    for (int i = 0; arg[i]; i++)
        if (!('0' <= arg[i] && arg[i] <= '9'))
            return false;
    return true;
}
