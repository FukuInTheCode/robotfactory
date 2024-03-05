/*
** EPITECH PROJECT, 2024
** parsing.c
** File description:
** parsing.c
*/

#include "my.h"
#include <stdio.h>
#include <sys/stat.h>

static int do_header(char *lines[5001], FILE *bin)
{
    char **argv = NULL;

    if (!my_strstr(lines[0], NAME_CMD_STRING))
        return 84;
    argv = my_str_to_word_array(lines[0], "\"");
    if (!is_name(argv, bin))
        return 84;
    if (!my_strstr(lines[1], COMMENT_CMD_STRING))
        return 84;
    my_free_str_array(argv);
    argv = my_str_to_word_array(lines[1], "\"");
    if (!is_comment(argv, bin))
        return 84;
    my_free_str_array(argv);
    return 0;
}

static int read_files(FILE *asmbly, FILE *bin)
{
    char *line = NULL;
    size_t len = 0;
    char **lines[5001] = {0};
    char *lines_arr[5001] = {0};
    int i = 0;

    for (int aa = getline(&line, &len, asmbly); aa != -1;
        aa = getline(&line, &len, asmbly)) {
        my_cleanstr(line, ' ', "\n\t,");
        lines_arr[i] = my_strdup(line);
        my_cleanstr(line, ' ', "\"");
        lines[i] = my_str_to_word_array(line, " ");
        i++;
    }
    if (do_header(lines_arr, bin) == 84)
        return 84;
    return 0;
}

int parsing(FILE *asmbly, FILE *bin)
{
    if (!asmbly || !bin)
        return 84;
    return read_files(asmbly, bin);
}
