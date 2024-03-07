/*
** EPITECH PROJECT, 2024
** write_st.c
** File description:
** function for write
*/

#include "my.h"
#include <stdint.h>

// faire un sizeof(uint8_t) si argv[2] est un registre au
// dernier write
static int write_coding(char **argv, FILE *bin)
{
    uint8_t coding_byte;

    if (is_register(argv[2])) {
        coding_byte = get_coding_byte(REGISTRE, REGISTRE, OTHER, OTHER);
        fwrite(&coding_byte, sizeof(coding_byte), 1, bin);
    }
    if (is_indirect(argv[2])) {
        coding_byte = get_coding_byte(REGISTRE, INDIRECT, OTHER, OTHER);
        fwrite(&coding_byte, sizeof(coding_byte), 1, bin);
    }
    return 0;
}

int write_st(char **argv, FILE *bin)
{
    unsigned char indicator = 0x03;
    uint8_t nbr = my_getnbr(argv[1] + 1);
    uint16_t nbr2 = my_getnbr(argv[2] + 1);
    uint8_t offset = 0;

    if (!bin)
        return 0;
    fwrite(&indicator, sizeof(indicator), 1, bin);
    write_coding(argv, bin);
    if (is_indirect(argv[2])) {
        nbr2 = my_revbyte_16(my_getnbr(argv[2]));
        offset = 1;
    }
    fwrite(&nbr, sizeof(uint8_t), 1, bin);
    fwrite(&nbr2, sizeof(uint8_t) + offset, 1, bin);
    return 0;
}
