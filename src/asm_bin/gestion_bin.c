/*
** EPITECH PROJECT, 2024
** gestion_asm.c
** File description:
** gestion of the asm
*/

#include "my.h"

int create_bin(FILE *asmbly, char *name_champ)
{
    FILE *bin;

    my_strcat(name_champ, ".cor");
    bin = fopen(name_champ, "wb");
    if (bin == NULL)
        return 84;
    if (parsing(asmbly, bin) == 84)
        return 84;
    fclose(bin);
    return 0;
}
