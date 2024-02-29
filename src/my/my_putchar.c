/*
** EPITECH PROJECT, 2024
** my_putchar.c
** File description:
** my_putchar.c for robot_factory
*/

#include "robot_factory.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
