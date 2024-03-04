/*
** EPITECH PROJECT, 2023
** Pool Day 08
** File description:
** Placeholder
*/

#include "my.h"

static int is_alphanum(char c, char const *sep)
{
    for (int i = 0; sep[i]; i++)
        if (sep[i] == c)
            return false;
    return true;
}

static int dup_str(char **ret, size_t sub_i, char *tmp, int i)
{
    ret[sub_i] = my_strdup(tmp + i);
    return my_strlen(tmp + i);
}

char **my_str_to_word_array(char const *str, char const *sep)
{
    char **ret = NULL;
    size_t count = 0;
    char *tmp = my_strdup(str);
    size_t sub_i = 0;

    for (int i = 0; str[i]; i++)
        if (is_alphanum(str[i], sep) != 0 && is_alphanum(str[i + 1], sep) == 0)
            count++;
    ret = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; str[i]; i++)
        tmp[i] -= tmp[i] * (is_alphanum(tmp[i], sep) == 0);
    for (int i = 0; str[i]; i++) {
        if (!tmp[i])
            continue;
        i += dup_str(ret, sub_i, tmp, i) - 1;
        sub_i++;
    }
    ret[count] = NULL;
    free(tmp);
    return ret;
}
