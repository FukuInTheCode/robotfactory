/*
** EPITECH PROJECT, 2024
** is_live.c
** File description:
** verifie if it's a live
*/

#include "my.h"

bool is_live(char **argv, FILE *bin)
{
    unsigned int len = 0;

    len = find_array_len(argv);
    if (len == 2 && my_strcmp(argv[0], "live") == 0 && argv[1] != NULL) {
        if (is_direct(argv[1]) == true)
            write_live(argv, bin);
        return true;
    }
    return false;
}
