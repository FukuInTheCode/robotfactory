/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** a function that returns a number sent to the
** fuction as a string
*/

int my_getnbr(char const *str)
{
    int result = 0;
    int signe = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            signe *= -1;
            continue;
        }
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            break;
        }
    }
    return (result * signe);
}
