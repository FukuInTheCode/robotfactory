/*
** EPITECH PROJECT, 2024
** code_byte.c
** File description:
** code_byte.c
*/

#include "my.h"

uint8_t get_coding_byte(arg_t arg1, arg_t arg2, arg_t arg3, arg_t arg4)
{
    uint8_t coding_byte = 0;

    coding_byte |= (arg1 & 0x03);
    coding_byte |= (arg2 & 0x03) << 2;
    coding_byte |= (arg3 & 0x03) << 4;
    coding_byte |= (arg4 & 0x03) << 6;
    return coding_byte;
}
