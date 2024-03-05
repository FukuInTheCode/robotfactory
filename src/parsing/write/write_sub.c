/*
** EPITECH PROJECT, 2024
** write_sub.c
** File description:
** function for write
*/

#include "my.h"
#include <stdint.h>

// same manque le coding byte

int write_sub(char **argv, FILE *bin)
{
    unsigned char indicator = 0x05;
    uint8_t nbr = my_getnbr(argv[1] + 1);
    uint8_t nbr2 = my_getnbr(argv[2] + 1);
    uint8_t nbr3 = my_getnbr(argv[3] + 1);

    fwrite(&indicator, sizeof(indicator), 1, bin);
    fwrite(&nbr, sizeof(uint8_t), 1, bin);
    fwrite(&nbr2, sizeof(uint8_t), 1, bin);
    fwrite(&nbr3, sizeof(uint8_t), 1, bin);
    return 0;
}
