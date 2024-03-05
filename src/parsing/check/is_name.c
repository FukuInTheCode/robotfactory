/*
** EPITECH PROJECT, 2024
** is_name.c
** File description:
** is_name.c
*/

#include "my.h"
#include "op.h"

bool is_name(char **argv, FILE *bin, header_t *header)
{
    int len = find_array_len(argv);
    char **tmp = NULL;

    if (len != 2)
        return false;
    tmp = my_str_to_word_array(*argv, " \t");
    len = find_array_len(tmp);
    if (len != 1 || my_strcmp(*tmp, NAME_CMD_STRING))
        return false;
    write_name(argv, bin, header);
    return true;
}
