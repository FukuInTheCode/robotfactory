/*
** EPITECH PROJECT, 2024
** write_zjmp.c
** File description:
** function for write
*/

#include "my.h"

int write_zjmp(char **argv, FILE *bin)
{
    unsigned char indicator = 0x09;
    uint16_t nbr = my_revbyte_16(my_getnbr(argv[1] + 1));

    fwrite(&indicator, sizeof(indicator), 1, bin);
    fwrite(&nbr, sizeof(uint16_t), 1, bin);
    return 0;
}
