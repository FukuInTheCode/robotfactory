/*
** EPITECH PROJECT, 2024
** write_ld.c
** File description:
** function for write
*/

#include "my.h"

// marche quand le premier arg est
// un indirect mais doit changer quand c un dire direct

int write_ld(char **argv, FILE *bin)
{
    unsigned char indicator = 0x02;
    uint8_t coding_byte;
    uint16_t nbr = my_revbyte_16(my_getnbr(argv[1]));
    uint8_t nbr2 = my_getnbr(argv[2] + 1);

    fwrite(&indicator, sizeof(indicator), 1, bin);
    if (is_direct(argv[1])) {
        coding_byte = get_coding_byte(DIRECT, REGISTRE, OTHER, OTHER);
        fwrite(&coding_byte, sizeof(coding_byte), 1, bin);
    }
    if (is_indirect(argv[1])) {
        coding_byte = get_coding_byte(INDIRECT, REGISTRE, OTHER, OTHER);
        fwrite(&coding_byte, sizeof(coding_byte), 1, bin);
    }
    fwrite(&nbr, sizeof(uint16_t), 1, bin);
    fwrite(&nbr2, sizeof(nbr2), 1, bin);
    return 0;
}
