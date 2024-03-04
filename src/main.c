/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c for robot_factory
*/

#include "my.h"

int main(int argc, char **argv)
{
    display_help(argc, argv, "src/assets/help.txt");
    if (robot_factory(argc, argv) == 84)
        return 84;
    return 0;
}
