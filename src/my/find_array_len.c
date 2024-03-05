/*
** EPITECH PROJECT, 2024
** find_array_len.c
** File description:
** find_array_len.c
*/

#include "my.h"

int find_array_len(char **argv)
{
    int len = 0;

    for (; argv[len]; len++);
    return len;
}
