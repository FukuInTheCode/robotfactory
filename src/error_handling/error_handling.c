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
    bool flag = false;

    if (fd == -1)
        return 84;
    for (int i = 0; path[i] != '\0'; i++) {
        if (!flag && path[i] == '.' && path[i + 1] == 's') {
            flag == true;
            return 0;
        }
    }
    if (flag == false) {
        close(fd);
        return 84;
    }
    close(fd);
    return 0;
}
