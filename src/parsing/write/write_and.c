/*
** EPITECH PROJECT, 2024
** write_and.c
** File description:
** function for write
*/

#include "my.h"

static int get_coding_byte_and_la_suite(char **argv, FILE *bin)
{
    int coding_byte;

    if (is_direct(argv[2]))
        coding_byte = get_coding_byte(REGISTRE, DIRECT, REGISTRE, OTHER);
    if (is_indirect(argv[2]))
        coding_byte = get_coding_byte(REGISTRE, INDIRECT, REGISTRE, OTHER);
    if (is_register(argv[2]))
        coding_byte = get_coding_byte(REGISTRE, REGISTRE, REGISTRE, OTHER);
    return coding_byte;
}

static int get_coding_byte_and(char **argv, FILE *bin)
{
    if (is_direct(argv[1])) {
        if (is_direct(argv[2]))
            return get_coding_byte(DIRECT, DIRECT, REGISTRE, OTHER);
        if (is_indirect(argv[2]))
            return get_coding_byte(DIRECT, INDIRECT, REGISTRE, OTHER);
        if (is_register(argv[2]))
            return get_coding_byte(DIRECT, REGISTRE, REGISTRE, OTHER);
    }
    if (is_indirect(argv[1])) {
        if (is_direct(argv[2]))
            return get_coding_byte(INDIRECT, DIRECT, REGISTRE, OTHER);
        if (is_indirect(argv[2]))
            return get_coding_byte(INDIRECT, INDIRECT, REGISTRE, OTHER);
        if (is_register(argv[2]))
            return get_coding_byte(INDIRECT, REGISTRE, REGISTRE, OTHER);
    }
    if (is_register(argv[1]))
        return get_coding_byte_and_la_suite(argv, bin);
    return 84;
}

unsigned long write_arg1_and(char **argv, FILE *bin)
{
    unsigned int nbr;
    uint16_t label = 0;

    if (is_label(argv[1])) {
        nbr = my_revbyte16(my_getnbr(argv[1] + 2));
        return fwrite(&label, sizeof(uint16_t), 1, bin);
    }
    if (is_direct(argv[1])) {
        nbr = my_revbyte32(my_getnbr(argv[1] + 1));
        return fwrite(&nbr, sizeof(int), 1, bin);
    }
    if (is_indirect(argv[1])) {
        nbr = my_revbyte16(my_getnbr(argv[1]));
        return fwrite(&nbr, sizeof(uint16_t), 1, bin);
    }
    if (is_register(argv[1])) {
        nbr = my_getnbr(argv[1] + 1);
        return fwrite(&nbr, sizeof(uint8_t), 1, bin);
    }
    return 84;
}

unsigned long write_arg2_and(char **argv, FILE *bin)
{
    unsigned int nbr;
    uint16_t label = 0;

    if (is_label(argv[1])) {
        nbr = my_revbyte16(my_getnbr(argv[1] + 2));
        return fwrite(&label, sizeof(uint16_t), 1, bin);
    }
    if (is_direct(argv[1])) {
        nbr = my_revbyte32(my_getnbr(argv[1] + 1));
        return fwrite(&nbr, sizeof(int), 1, bin);
    }
    if (is_indirect(argv[1])) {
        nbr = my_revbyte16(my_getnbr(argv[1]));
        return fwrite(&nbr, sizeof(uint16_t), 1, bin);
    }
    if (is_register(argv[1])) {
        nbr = my_getnbr(argv[1] + 1);
        return fwrite(&nbr, sizeof(uint8_t), 1, bin);
    }
    return 84;
}

int write_and(char **argv, FILE *bin)
{
    unsigned char indicator = 0x06;
    unsigned int coding_byte;
    uint8_t nbr3 = my_getnbr(argv[3] + 1);

    fwrite(&indicator, sizeof(indicator), 1, bin);
    coding_byte = my_revbyte32(get_coding_byte_and(argv, bin));
    if (coding_byte == 84)
        return 84;
    fwrite(&coding_byte, sizeof(coding_byte), 1, bin);
    if (write_arg1_and(argv, bin) == 84 || write_arg2_and(argv, bin) == 84)
        return 84;
    fwrite(&nbr3, sizeof(uint8_t), 1, bin);
    return 0;
}
