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

void my_putchar(char);
char *my_strdup(char const *);
int my_strlen(char const *);
char **my_str_to_word_array(char const *, char const *);
int my_free_str_array(char **);
char *my_strcat(char *, char const *);
int my_revbyte(int);
int my_strcmp(char const *, char const *);
int my_getnbr(char const *);
int find_array_len(char **);
int my_cleanstr(char *, char, char const *);
int my_strstr(char const *, char const *);

int display_help(int , char **, char const *);
int parsing(FILE *, FILE *);
int robot_factory(int, char **);
int open_file(char *);
int gestion_asm_bin(char const *);
int open_asm(char const *);
int create_bin(FILE *, char *);

int write_live(char **, FILE *);
int write_name(char **, FILE *);
int write_comment(char **, FILE *);

bool is_direct(char const *);
bool is_label(char const *);
bool is_indirect(char const *);
bool is_register(char const *);


bool is_live(char **, FILE*);
bool is_comment(char **, FILE*);
bool is_name(char **, FILE*);

typedef bool(*is_func)(char **, FILE *);

typedef struct func {
    is_func f;
} is_func_t;

static is_func_t const is_functions_array[] = {
    {is_live},
    {NULL},
};
