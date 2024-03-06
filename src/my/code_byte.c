/*
** EPITECH PROJECT, 2024
** code_byte.c
** File description:
** code_byte.c
*/

#include "my.h"

uint8_t get_coding_byte(arg_t arg1, arg_t arg2, arg_t arg3, arg_t arg4)
{
    return (arg1 << 6) | (arg2 << 4) | (arg3 << 2) | arg4;
}
