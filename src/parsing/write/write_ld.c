/*
** EPITECH PROJECT, 2024
** write_ld.c
** File description:
** function for write
*/

#include "my.h"

int write_ld(char **argv, FILE *bin)
{
    unsigned char indicator = 0x02;
    unsigned int coding_byte;
    unsigned int nbr = my_getnbr(argv[1]);
    unsigned int nbr2 = my_getnbr(argv[1] + 1);

    fwrite(&indicator, sizeof(indicator), 1, bin);
    if (is_direct(argv[1])) {
        coding_byte = get_coding_byte(DIRECT, REGISTRE, OTHER, OTHER);
        fwrite(&coding_byte, sizeof(coding_byte), 1, bin);
    }
    if (is_indirect(argv[1])) {
        coding_byte = get_coding_byte(INDIRECT, REGISTRE, OTHER, OTHER);
        fwrite(&coding_byte, sizeof(coding_byte), 1, bin);
    }
    fwrite(&nbr, sizeof(nbr), 1, bin);
    fwrite(&nbr2, sizeof(nbr2), 1, bin);
    return 0;
}
