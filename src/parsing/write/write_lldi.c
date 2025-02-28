/*
** EPITECH PROJECT, 2024
** write_ldi.c
** File description:
** function for write
*/

#include "my.h"

static unsigned long write_arg1(char **argv, FILE *bin)
{
    unsigned int nbr;

    if (is_register(argv[1])) {
        nbr = my_getnbr(argv[1] + 1);
        return fwrite(&nbr, sizeof(uint8_t), 1, bin);
    }
    if (is_direct(argv[1]) || is_indirect(argv[1])) {
        nbr = my_revbyte_16(my_getnbr(argv[1] + is_direct(argv[1])));
        return fwrite(&nbr, sizeof(uint16_t), 1, bin);
    }
    return 0;
}

static unsigned long write_arg2(char **argv, FILE *bin)
{
    unsigned int nbr;

    if (is_register(argv[2])) {
        nbr = my_getnbr(argv[2] + 1);
        return fwrite(&nbr, sizeof(uint8_t), 1, bin);
    }
    if (is_direct(argv[2]) || is_indirect(argv[2])) {
        nbr = my_revbyte_16(my_getnbr(argv[2] + is_direct(argv[2])));
        return fwrite(&nbr, sizeof(uint16_t), 1, bin);
    }
    return 0;
}


static uint8_t get_coding_byte_lldi2(char **argv)
{
    if (is_indirect(argv[1])) {
        if (is_direct(argv[2]))
            return get_coding_byte(INDIRECT, DIRECT, REGISTRE, OTHER);
        if (is_register(argv[2]))
            return get_coding_byte(INDIRECT, REGISTRE, REGISTRE, OTHER);
        if (is_indirect(argv[2]))
            return get_coding_byte(INDIRECT, INDIRECT, REGISTRE, OTHER);
    }
    return 0;
}

static uint8_t get_coding_byte_lldi(char **argv)
{
    if (is_direct(argv[1])) {
        if (is_direct(argv[2]))
            return get_coding_byte(DIRECT, DIRECT, REGISTRE, OTHER);
        if (is_register(argv[2]))
            return get_coding_byte(DIRECT, REGISTRE, REGISTRE, OTHER);
        if (is_indirect(argv[2]))
            return get_coding_byte(DIRECT, INDIRECT, REGISTRE, OTHER);
    }
    if (is_register(argv[1])) {
        if (is_direct(argv[2]))
            return get_coding_byte(REGISTRE, DIRECT, REGISTRE, OTHER);
        if (is_register(argv[2]))
            return get_coding_byte(REGISTRE, REGISTRE, REGISTRE, OTHER);
        if (is_indirect(argv[2]))
            return get_coding_byte(REGISTRE, INDIRECT, REGISTRE, OTHER);
    }
    return get_coding_byte_lldi2(argv);
}

int write_lldi(char **argv, FILE *bin)
{
    unsigned char indicator = 0x0e;
    uint8_t coding_byte;
    uint8_t nbr = my_getnbr(argv[3] +1);

    if (!bin)
        return 0;
    fwrite(&indicator, sizeof(indicator), 1, bin);
    coding_byte = get_coding_byte_lldi(argv);
    fwrite(&coding_byte, sizeof(uint8_t), 1, bin);
    write_arg1(argv, bin);
    write_arg2(argv, bin);
    fwrite(&nbr, sizeof(uint8_t), 1, bin);
    return 0;
}
