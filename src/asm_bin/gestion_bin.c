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
    unsigned int magic = COREWAR_EXEC_MAGIC;

    name_champ = realloc(name_champ, my_strlen(name_champ) + 5);
    magic = my_revbyte(magic);
    my_strcat(name_champ, ".cor");
    bin = fopen(name_champ, "wb");
    if (bin == NULL)
        return 84;
    fwrite(&magic, sizeof(unsigned int), 1, bin);
    if (parsing(asmbly, bin) == 84)
        return 84;
    fclose(bin);
    return 0;
}
