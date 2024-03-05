/*
** EPITECH PROJECT, 2024
** is_st.c
** File description:
** verify if it's a st
*/

#include "my.h"

bool is_st(char **argv, FILE *bin)
{
    if (my_strcmp(argv[0], "st") == 0 && find_array_len(argv) == 3 && is_register(argv[1]) && (is_register(argv[2]) || is_indirect(argv[2]))) {
        write_st(argv, bin);
        return true;
    }
    return false;
}
