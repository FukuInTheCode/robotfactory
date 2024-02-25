/*
** EPITECH PROJECT, 2024
** parsing.c
** File description:
** parsing.c
*/

#include "my.h"

static int get_str_array_len(char **)
{
    size_t len = 0;

    for (; array[len]; len++);
    return len;
}

static bool handle_line(char const *line, FILE *bin)
{
    int is_nbr = 0;
    char **argv = my_str_to_word_array(line);
    int argc = get_str_array_len(argv);

    for (uint8_t i = 0; is_functions_array[i]; i++) {
        is_nbr += is_functions_array[i](argc, argv, bin);
        if (is_nbr > 1)
            return false;
    }
    return true;
}

static int read_files(FILE *asmbly, FILE *bin)
{
    char *line = NULL;
    size_t len = 0;

    for (int len = getline(&line, &len, asmbly); len != -1;
        len = getline(&line, &len, asmbly))
            if (!handle_line(line, bin))
                return 84;
    return 0;
}

int parsing(FILE *asmbly, FILE *bin)
{
    if (!asmbly || !bin)
        return 84;
    return read_files(asmbly, bin);
}
