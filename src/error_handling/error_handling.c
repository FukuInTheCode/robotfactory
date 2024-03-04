/*
** EPITECH PROJECT, 2024
** error_handling.c
** File description:
** gestion of the error handling
*/

#include "my.h"



int open_file(char *path)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1)
        return 84;
    for (int i = 0; path[i] != '\0'; i++) {
        if (path[i] == '.' && path[i + 1] == 's') {
            close(fd);
            return 0;
        }
    }
    close(fd);
    return 84;
}
