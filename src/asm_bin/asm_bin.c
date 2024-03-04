/*
** EPITECH PROJECT, 2024
** asm_bin.c
** File description:
** gestion of the asm and the bin file
*/

#include "my.h"

int gestion_asm_bin(char const *path)
{
    if (open_asm(path) == 84)
        return 84;
    return 0;
}
