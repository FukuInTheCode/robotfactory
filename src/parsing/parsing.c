/*
** EPITECH PROJECT, 2024
** parsing.c
** File description:
** parsing.c
*/

#include "my.h"
#include <stdio.h>
#include <sys/stat.h>

static int do_header(FILE *asmbly, FILE *bin, char *line, size_t len)
{
    char **argv = NULL;

    if (getline(&line, &len, asmbly) == -1)
        return 84;
    argv = my_str_to_word_array(line, "\"");
    if (!is_name(argv, bin))
        return 84;
    my_free_str_array(argv);
    if (getline(&line, &len, asmbly) == -1)
        return 84;
    argv = my_str_to_word_array(line, "\"");
    if (!is_comment(argv, bin))
        return 84;
    my_free_str_array(argv);
    return 0;
}

static bool handle_line(char const *line, FILE *bin)
{
    int is_nbr = 0;
    char **argv = my_str_to_word_array(line, "\t ");

    for (uint8_t i = 0; is_functions_array[i].f; i++) {
        is_nbr += is_functions_array[i].f(argv, bin);
        if (is_nbr != 1)
            return false;
    }
    my_free_str_array(argv);
    return true;
}

static int read_files(FILE *asmbly, FILE *bin)
{
    char *line = NULL;
    size_t len = 0;

    if (do_header(asmbly, bin, line, len) == 84)
        return 84;
    for (int aa = getline(&line, &len, asmbly); aa != -1;
        aa = getline(&line, &len, asmbly)) {
        line[aa - 1] = 0;
        if (!handle_line(line, bin))
            return 84;
    }
    return 0;
}

int parsing(FILE *asmbly, FILE *bin)
{
    if (!asmbly || !bin)
        return 84;
    return read_files(asmbly, bin);
}
