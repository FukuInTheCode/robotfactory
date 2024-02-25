/*
** EPITECH PROJECT, 2024
** parsing.c
** File description:
** parsing.c
*/

#include "my.h"

static int read_files(FILE *asmbly, FILE *bin)
{
    char *line = NULL;
    size_t len = 0;

    for (int len = getline(&line, &len, asmbly); len != -1;
        len = getline(&line, &len, asmbly))
            if (!handle_line(line, len))
                return 84;
    return 0;
}

int parsing(FILE *asmbly, FILE *bin)
{
    if (!asmbly || !bin)
        return 84;
    return read_files(asmbly, bin);
}
