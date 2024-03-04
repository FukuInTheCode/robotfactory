/*
** EPITECH PROJECT, 2024
** is_name.c
** File description:
** is_name.c
*/

#include "my.h"

bool is_name(char **argv, FILE *bin)
{
    int len = find_argv_len(argv);
    char **tmp = NULL;

    if (len != 2)
        return false;
    tmp = my_str_to_word_array(*argv, " \t");
    len = find_argv_len(tmp);
    if (len != 1 || my_strcmp(tmp, ".name"))
        return false;
    write_name(argv, bin);
    return true;
}
