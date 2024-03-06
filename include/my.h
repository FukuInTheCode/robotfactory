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

typedef enum arg_e {
    OTHER = 0,
    REGISTRE = 1,
    DIRECT = 2,
    INDIRECT = 3
} arg_t;

uint8_t get_coding_byte(arg_t arg1, arg_t arg2, arg_t arg3, arg_t arg4);

void my_putchar(char);
char *my_strdup(char const *);
int my_strlen(char const *);
char **my_str_to_word_array(char const *, char const *);
int my_free_str_array(char **);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
int my_getnbr(char const *);
int find_array_len(char **);
int my_cleanstr(char *, char, char const *);
char *my_strstr(char const *, char const *);
int my_strncmp(char const *, char const *, int);
uint8_t my_revbyte_8(uint8_t);
uint16_t my_revbyte_16(uint16_t);
uint32_t my_revbyte_32(uint32_t);

int display_help(int, char **, char const *);
int parsing(FILE *, FILE *);
int robot_factory(int, char **);
int open_file(char *);
int gestion_asm_bin(char const *);
int open_asm(char const *);
int create_bin(FILE *, char *);

int write_live(char **, FILE *);
int write_name(char **, FILE *, header_t *);
int write_comment(char **, FILE *, header_t *);
int write_ld(char **, FILE *);
int write_st(char **, FILE *);
int write_add(char **, FILE *);
int write_sub(char **, FILE *);
int write_and(char **, FILE *);
int write_xor(char **, FILE *);
int write_or(char **, FILE *);

bool is_direct(char const *);
bool is_label(char const *);
bool is_indirect(char const *);
bool is_register(char const *);


int count_live(char **);
int count_st(char **);
int count_ld(char **);
int count_add(char **);
int count_sub(char **);
int count_and(char **);
int count_or(char **);
int count_xor(char **);
int count_zjmp(char **);
int count_ldi(char **);
int count_sti(char **);
int count_fork(char **);
int count_lld(char **);
int count_lldi(char **);
int count_aff(char **);

bool is_live(char **, FILE *);
bool is_comment(char **, FILE *, header_t *);
bool is_name(char **, FILE *, header_t *);
bool is_ld(char **, FILE *);
bool is_st(char **, FILE *);
bool is_add(char **, FILE *);
bool is_and(char **, FILE *);
bool is_sub(char **, FILE *);
bool is_xor(char **, FILE *);
bool is_or(char **, FILE *);



typedef bool(*is_func)(char **, FILE *);

typedef struct func {
    is_func f;
} is_func_t;

static is_func_t const is_functions_array[] = {
    {is_live},
    {is_or},
    {is_xor},
    {is_ld},
    {is_st},
    {is_add},
    {is_sub},
    {is_and},
    {NULL},
};

typedef int(*count_func)(char **);

typedef struct cfunc {
    count_func f;
} count_func_t;

static count_func_t const count_functions_array[] = {
    {count_live},
    {count_st},
    {count_ld},
    {count_add},
    {count_sub},
    {count_and},
    {count_or},
    {count_xor},
    {count_zjmp},
    {count_ldi},
    {count_sti},
    {count_fork},
    {count_lld},
    {count_lldi},
    {count_aff},
    {NULL},
};
