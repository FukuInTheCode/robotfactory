/*
** EPITECH PROJECT, 2024
** write_name.c
** File description:
** write_name.c
*/

#include "my.h"
#include "op.h"

int write_name(char **argv, FILE *bin, header_t *header)
{
    my_strcat(header->prog_name, argv[1]);
    return 0;
}
