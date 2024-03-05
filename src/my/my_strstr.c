/*
** EPITECH PROJECT, 2024
** my_strstr.c
** File description:
** my_strstr.c
*/

#include "my.h"

char *my_strstr(char const *s1, char const *s2)
{
    for (int i = 0; s1[i]; i++)
        if (!my_strncmp(s1 + i, s2, my_strlen(s2)))
            return (char *)s1 + i;
    return NULL;
}
