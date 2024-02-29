/*
** EPITECH PROJECT, 2024
** tests.c
** File description:
** tests.c
*/

#include "my.h"

int main(void)
{
    if (parsing(NULL, NULL) != 84)
        return 84;
    FILE *file = fopen("../champions/champion.s", "r");
    FILE *bin = fopen("tmp.cor", "w");
    if (parsing(file, bin) != 84)
        return 84;
    return 0;
}
