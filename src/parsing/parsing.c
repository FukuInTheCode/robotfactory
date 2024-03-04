/*
** EPITECH PROJECT, 2024
** parsing.c
** File description:
** parsing.c
*/

#include "my.h"

static bool handle_line(char const *line,
    FILE *bin, label_t *labels, char const *bin_name)
{
    int is_nbr = 0;
    char **argv = my_str_to_word_array(line, "\t ");
    struct stat s;

    for (uint8_t i = 0; is_functions_array[i].f; i++) {
        if (stat(bin_name, &s))
            return false;
        is_nbr += is_functions_array[i].f(argv, bin, labels, s.st_size);
        if (is_nbr != 1)
            return false;
    }
    my_free_str_array(argv);
    return true;
}

static int read_files(FILE *asmbly, FILE *bin,
    label_t *labels, chat const *bin_name)
{
    char *line = NULL;
    size_t len = 0;
    int position = 0;

    for (;getline(&line, &len, asmbly) != -1;) {
            line[len] = 0;
            if (!handle_line(line, bin, labels))
                return 84;
    }
    return 0;
}

int parsing(FILE *asmbly, FILE *bin, label_t *labels, char const *bin_name)
{
    if (!asmbly || !bin)
        return 84;
    return read_files(asmbly, bin, labels, bin_name);
}
