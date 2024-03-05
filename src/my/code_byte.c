/*
** EPITECH PROJECT, 2024
** code_byte.c
** File description:
** code_byte.c
*/

#include "my.h"

uint8_t get_coding_byte(arg_t arg1, arg_t arg2, arg_t arg3, arg_t arg4)
{
    uint8_t ret = 0;

    ret = (ret >> 2) + arg4;
    ret = (ret >> 2) + arg3;
    ret = (ret >> 2) + arg2;
    ret = (ret >> 2) + arg1;
    return ret;
}
