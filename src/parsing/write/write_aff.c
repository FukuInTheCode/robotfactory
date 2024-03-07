/*
** EPITECH PROJECT, 2024
** write_aff.c
** File description:
** function for write
*/

#include "my.h"

int write_aff(char **argv, FILE *bin)
{
    unsigned char indicator = 0x10;
    uint8_t coding_byte = get_coding_byte(REGISTRE, OTHER, OTHER, OTHER);
    uint8_t nbr = my_getnbr(argv[1] + 1);

    if (!bin)
        return 0;
    fwrite(&indicator, sizeof(indicator), 1, bin);
    fwrite(&coding_byte, sizeof(uint8_t), 1, bin);
    fwrite(&nbr, sizeof(uint8_t), 1, bin);
    return 0;
}
