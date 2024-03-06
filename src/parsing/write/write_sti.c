/*
** EPITECH PROJECT, 2024
** write_sti.c
** File description:
** function for write
*/

#include "my.h"

static unsigned long write_coding_byte(char **argv, FILE* bin)
{
    uint8_t coding_byte;

    if (is_register(argv[2])) {
        if (is_register(argv[3])) {
            coding_byte = get_coding_byte(REGISTRE, REGISTRE, REGISTRE, OTHER);
            return fwrite(&coding_byte, sizeof(uint8_t), 1, bin);
        }
        if (is_direct(argv[3])) {
            coding_byte = get_coding_byte(REGISTRE, REGISTRE, DIRECT, OTHER);
            return fwrite(&coding_byte, sizeof(uint8_t), 1, bin);
        }
    }
    if (is_direct(argv[2])) {
        if (is_register(argv[3])) {
            coding_byte = get_coding_byte(REGISTRE, DIRECT, REGISTRE, OTHER);
            return fwrite(&coding_byte, sizeof(uint8_t), 1, bin);
        }
        if (is_direct(argv[3])) {
            coding_byte = get_coding_byte(REGISTRE, DIRECT, DIRECT, OTHER);
            return fwrite(&coding_byte, sizeof(uint8_t), 1, bin);
        }
    }
    return 0;
}

static unsigned long write_arg3(char **argv, FILE *bin)
{
    unsigned int nbr;

    if (is_direct(argv[3])) {
        nbr = my_revbyte_32(my_getnbr(argv[3] + 1));
        fwrite(&nbr, sizeof(int), 1, bin);
    }
    if (is_register(argv[3])) {
        nbr = my_getnbr(argv[3] + 1);
        fwrite(&nbr, sizeof(uint8_t), 1, bin);
    }
    return 0;
}

static unsigned long write_arg2(char **argv, FILE *bin)
{
    unsigned int nbr;

    if (is_direct(argv[2])) {
        nbr = my_revbyte_32(my_getnbr(argv[2] + 1));
        fwrite(&nbr, sizeof(int), 1, bin);
    }
    if (is_register(argv[2])) {
        nbr = my_getnbr(argv[2] + 1);
        fwrite(&nbr, sizeof(uint8_t), 1, bin);
    }
    return 0;
}

int write_sti(char **argv, FILE *bin)
{
    unsigned char indicator = 0x0b;
    uint8_t nbr = my_getnbr(argv[1] + 1);

    fwrite(&indicator, sizeof(indicator), 1, bin);
    write_coding_byte(argv, bin);
    fwrite(&nbr, sizeof(uint8_t), 1, bin);
    write_arg2(argv, bin);
    write_arg3(argv, bin);
    return 0;
}