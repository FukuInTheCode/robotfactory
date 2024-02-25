/*
** EPITECH PROJECT, 2024
** my_free_str_array.c
** File description:
** my_free_str_array.c
*/

#include "my.h"

int my_free_str_array(char **array)
{
    if (!array)
        return 84;
    for (uint32_t i = 0; array[i]; i++)
        free(array[i]);
    free(array);
    return 0;
}
