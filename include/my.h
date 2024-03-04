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
    #include <stdbool.h>
    #include <stdint.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "op.h"

typedef struct label_s {
    char *name;
    int position;
} label_t;

void my_putchar(char c);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char **my_str_to_word_array(char const *, char const *);
int my_free_str_array(char **);

int display_help(int argc, char **argv, char const *path);
int parsing(FILE *, FILE *, label_t *, char const *);

typedef bool(*is_func)(char **, FILE *, label_t *, int);

typedef struct func {
    is_func f;
} is_func_t;

static is_func_t const is_functions_array[] = {
    {NULL},
};
