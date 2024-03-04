/*
** EPITECH PROJECT, 2024
** write_comment.c
** File description:
** write_comment.c
*/

#include "my.h"

int write_comment(char **argv, FILE *bin)
{
    char comment[COMMENT_LENGTH];

    for (int i = 0; i < COMMENT_LENGTH; i++)
        comment[i] = 0;
    my_strcat(comment, argv[1]);
    fwrite(&comment, sizeof(comment), 1, bin);
    return 0;
}
