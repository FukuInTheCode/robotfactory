/*
** EPITECH PROJECT, 2024
** write_comment.c
** File description:
** write_comment.c
*/

#include "my.h"
#include "op.h"

int write_comment(char **argv, FILE *bin, header_t *header)
{
    my_strcat(header->comment, argv[1]);
    return 0;
}
