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

void my_putchar(char c);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char **my_str_to_word_array(char const *, char const *);
int my_free_str_array(char **);
char *my_strcat(char *dest, char const *src);
int my_revbyte(int);
int find_array_len(char **);

int display_help(int argc, char **argv, char const *path);
int parsing(FILE *, FILE *);
int robot_factory(int argc, char **argv);
int open_file(char *path);
int gestion_asm_bin(char const *path);
int open_asm(char const *);
int create_bin(FILE *asmbly, char *name_champ);

bool is_direct(char const *);

typedef bool(*is_func)(char **, FILE *);

typedef struct func {
    is_func f;
} is_func_t;

static is_func_t const is_functions_array[] = {
    {NULL},
};
