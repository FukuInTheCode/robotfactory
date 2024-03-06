/*
** EPITECH PROJECT, 2024
** write_ld.c
** File description:
** function for write
*/

#include "my.h"
#include <stdint.h>

// marche quand le premier arg est
// un indirect mais doit changer quand c un dire direct

static int write_coding(char **argv, FILE *bin)
{
    uint8_t coding_byte;

    if (is_direct(argv[1])) {
        coding_byte = get_coding_byte(DIRECT, REGISTRE, OTHER, OTHER);
        fwrite(&coding_byte, sizeof(coding_byte), 1, bin);
    }
    if (is_indirect(argv[1])) {
        coding_byte = get_coding_byte(INDIRECT, REGISTRE, OTHER, OTHER);
        fwrite(&coding_byte, sizeof(coding_byte), 1, bin);
    }
    return 0;
}

int write_lld(char **argv, FILE *bin)
{
    unsigned char indicator = 0x0d;
    uint32_t nbr = my_revbyte_16(my_getnbr(argv[1]));
    uint8_t nbr2 = my_getnbr(argv[2] + 1);
    uint8_t offset = 0;

    fwrite(&indicator, sizeof(indicator), 1, bin);
    write_coding(argv, bin);
    if (is_direct(argv[1])) {
        nbr = my_revbyte_32(my_getnbr(argv[1] + 1));
        offset = 2;
    }
    fwrite(&nbr, sizeof(uint16_t) + offset, 1, bin);
    fwrite(&nbr2, sizeof(uint8_t), 1, bin);
    return 0;
}
