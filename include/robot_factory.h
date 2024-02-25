/*
** EPITECH PROJECT, 2024
** robot_factory .h
** File description:
** header for robot_factory
*/

#pragma once
    #define ROBOT_FACTORY_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

void my_putchar(char c);
char **my_str_to_word_array(char const *);
int my_free_str_array(char **);

int parsing(FILE *, FILE *);

typedef bool(*is_func)(int, char **, FILE *);

static const is_func is_functions_array[] = {
    NULL
    };
