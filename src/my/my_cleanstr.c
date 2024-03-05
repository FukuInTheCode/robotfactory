/*
** EPITECH PROJECT, 2024
** my_cleanstr.c
** File description:
** my_cleanstr.c
*/

#include "my.h"

static bool is_replace(char c, char const *to_replace)
{
    for (int i = 0; to_replace[i]; i++)
        if (c == to_replace[i])
            return true;
    return false;
}

int my_cleanstr(char *str, char c, char const *to_replace)
{
    for (int i = 0; str[i]; i++) {
        if (!is_replace(str[i], to_replace))
            continue;
        str[i] = c;
    }
    return 0;
}
