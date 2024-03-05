/*
** EPITECH PROJECT, 2024
** write_live.c
** File description:
** write in bin for 'live'
*/

#include "my.h"

int write_live(char **argv, FILE *bin)
{
    unsigned char indicator = 0x01;
    unsigned int nbr = my_revbyte_32(my_getnbr(argv[1] + 1));

    fwrite(&indicator, sizeof(indicator), 1, bin);
    fwrite(&nbr, sizeof(nbr), 1, bin);
    return 0;
}
