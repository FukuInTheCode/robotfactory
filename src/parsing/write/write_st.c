/*
** EPITECH PROJECT, 2024
** write_st.c
** File description:
** function for write
*/

#include "my.h"

int write_st(char **argv, FILE *bin)
{
    unsigned char indicator = 0x03;
    unsigned int coding_byte;
    unsigned int nbr = my_revbyte_32(my_getnbr(argv[1]));
    unsigned int nbr2;

    fwrite(&indicator, sizeof(indicator), 1, bin);
    if (is_register(argv[2])) {
        coding_byte = get_coding_byte(REGISTRE, REGISTRE, OTHER, OTHER);
        fwrite(&coding_byte, sizeof(coding_byte), 1, bin);
        nbr2 = my_revbyte_32(my_getnbr(argv[2] + 1));
    }
    if (is_indirect(argv[2])) {
        coding_byte = get_coding_byte(REGISTRE, INDIRECT, OTHER, OTHER);
        fwrite(&coding_byte, sizeof(coding_byte), 1, bin);
        nbr2 = my_revbyte_32(my_getnbr(argv[2]));
    }
    fwrite(&nbr, sizeof(nbr), 1, bin);
    fwrite(&nbr2, sizeof(nbr2), 1, bin);
    return 0;
}
