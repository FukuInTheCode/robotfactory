/*
** EPITECH PROJECT, 2024
** parsing.c
** File description:
** parsing.c
*/

#include "my.h"
#include <sys/stat.h>

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

    for (; getline(&line, &len, asmbly) != -1;) {
            line[len] = 0;
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
