/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c for robot_factory
*/

#include "my.h"

int main(int argc, char **argv)
{
    if (display_help(argc, argv, "src/assets/help.txt"))
        return 0;
    return 84;
}
