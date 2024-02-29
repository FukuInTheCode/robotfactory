/*
** EPITECH PROJECT, 2024
** parsing.c
** File description:
** parsing.c
*/

#include "my.h"

static bool handle_line(char const *line, FILE *bin, labels_t *labels, int pos)
{
    int is_nbr = 0;
    char **argv = my_str_to_word_array(line);

    for (uint8_t i = 0; is_functions_array[i]; i++) {
        is_nbr += is_functions_array[i](argv, bin, labels, pos);
        if (is_nbr > 1)
            return false;
    }
    my_free_str_array(argv);
    return true;
}

static int read_files(FILE *asmbly, FILE *bin, labels_t *labels)
{
    char *line = NULL;
    size_t len = 0;
    int position = 0;

    for (int len = getline(&line, &len, asmbly); len != -1;
        len = getline(&line, &len, asmbly)) {
            position += len - 1;
            line[len] = 0;
            if (!handle_line(line, bin, labels, position))
                return 84;
    }
    return 0;
}

int parsing(FILE *asmbly, FILE *bin, labels_t *labels)
{
    if (!asmbly || !bin)
        return 84;
    return read_files(asmbly, bin, labels);
}
