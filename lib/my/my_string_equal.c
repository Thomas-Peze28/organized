/*
** EPITECH PROJECT, 2024
** organized
** File description:
** is string are same
*/

#include "my.h"

int my_str_eq(char *str1, char *str2)
{
    int len_str1 = my_strlen(str1);
    int len_str2 = my_strlen(str2);

    if (len_str1 != len_str2)
        return -1;
    for (int i = 0; i < len_str1; i++) {
        if (str1[i] != str2[i])
            return -1;
    }
    return 0;
}
