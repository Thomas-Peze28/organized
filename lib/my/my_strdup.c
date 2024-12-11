/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** Allocate memory and copy a string in it
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src)) + 1);
    for (int count = 0; count < my_strlen(src); count++) {
        dest[count] = src[count];
    }
    dest[my_strlen(dest) + 1] = '\0';
    return dest;
}
