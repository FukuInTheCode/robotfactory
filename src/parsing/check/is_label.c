/*
** EPITECH PROJECT, 2024
** is_direct.c
** File description:
** is_direct.c
*/

#include "my.h"
#include "op.h"

static bool is_label_char(char c)
{
    for (int i = 0; LABEL_CHARS[i]; i++)
        if (c == LABEL_CHARS[i])
            return true;
    return false;
}

bool is_label(char const *arg)
{
    if (*arg != DIRECT_CHAR || arg[1] != LABEL_CHAR || !arg[2])
        return false;
    for (int i = 1; arg[i]; i++)
        if (!is_label_char(arg[i]))
            return false;
    return true;
}
