/*
** EPITECH PROJECT, 2024
** is_comment.c
** File description:
** is_comment.c
*/

#include "my.h"
#include "op.h"

bool is_comment(char **argv, FILE *bin, header_t *header)
{
    char **tmp = NULL;

    if (find_array_len(argv) != 2 || my_strlen(argv[1]) > COMMENT_LENGTH)
        return false;
    tmp = my_str_to_word_array(*argv, " \t");
    if (find_array_len(tmp) != 1 || my_strcmp(*tmp, COMMENT_CMD_STRING))
        return false;
    write_comment(argv, bin, header);
    return true;
}
