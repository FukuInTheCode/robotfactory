/*
** EPITECH PROJECT, 2024
** write_sub.c
** File description:
** function for write
*/

#include "my.h"

int write_sub(char **argv, FILE *bin)
{
    unsigned char indicator = 0x05;
    unsigned int nbr = my_revbyte(my_getnbr(argv[1] + 1));
    unsigned int nbr2 = my_revbyte(my_getnbr(argv[2] + 1));
    unsigned int nbr3 = my_revbyte(my_getnbr(argv[3] + 1));

    fwrite(&indicator, sizeof(indicator), 1, bin);
    fwrite(&nbr, sizeof(nbr), 1, bin);
    fwrite(&nbr2, sizeof(nbr2), 1, bin);
    fwrite(&nbr3, sizeof(nbr3), 1, bin);
    return 0;
}
