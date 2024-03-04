/*
** EPITECH PROJECT, 2024
** robot_factory.c
** File description:
** project robot factory
*/

#include "my.h"

int robot_factory(int argc, char **argv)
{
    if (argc != 2 || open_file(argv[1]) == 84)
        return 84;
    return 0;
}
