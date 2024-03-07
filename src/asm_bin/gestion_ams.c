/*
** EPITECH PROJECT, 2024
** gestion_asm.c
** File description:
** gestion of the asm
*/

#include "my.h"

char *get_name(char const *path)
{
    char *name = my_strdup(path);

    if (name == NULL)
        return NULL;
    for (int i = 0; name[i + 1] != '\0'; i++) {
        if (name[i] == '.' && name[i + 1] == 's' && name[i + 2] == '\0')
            name[i] = '\0';
    }
    return name;
}

int open_asm(char const *path)
{
    FILE *fd = fopen(path, "r");
    char *name;

    if (fd == NULL)
        return 84;
    if (parsing(fd, NULL) == 84)
        return 84;
    fseek(fd, 0, SEEK_SET);
    name = get_name(path);
    if (create_bin(fd, name) == 84)
        return 84;
    fclose(fd);
    return 0;
}
