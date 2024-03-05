/*
** EPITECH PROJECT, 2024
** my_revbyte.c
** File description:
** my_revbyte.c
*/

#include "my.h"

int my_revbyte(int num)
{
    int ret = 0;

    ret |= (num & 0xFF) << 24;
    ret |= ((num >> 8) & 0xFF) << 16;
    ret |= ((num >> 16) & 0xFF) << 8;
    ret |= (num >> 24) & 0xFF;
    return ret;
}
