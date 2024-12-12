/*
** EPITECH PROJECT, 2024
** organized
** File description:
** adding nodes
*/

#include "include/my.h"
#include "include/bootstrap.h"
#include "libshell/shell.h"

int is_good_type(char *str)
{
    if (my_str_eq(str, "WIRE") == 0 || my_str_eq(str, "wire") == 0) {
        return 0;
    }
    if (my_str_eq(str, "DEVICE") == 0 || my_str_eq(str, "device") == 0) {
        return 0;
    }
    if (my_str_eq(str, "PROCESSOR") == 0 || my_str_eq(str, "processor") == 0) {
        return 0;
    }
    if (my_str_eq(str, "SENSOR") == 0 || my_str_eq(str, "sensor") == 0) {
        return 0;
    }
    if (my_str_eq(str, "ACTUATOR") == 0 || my_str_eq(str, "actuator") == 0) {
        return 0;
    }
    my_printf("Type not recognized\n");
    return -1;
}

int add_handling(void *data, char **args)
{
    int i = 0;
    int j = 0;
    int count_args = 0;

    while (args[i] != NULL) {
        count_args++;
        i++;
    }
    if ((count_args % 2) != 0) {
        my_printf("It must be a peer number of argument\n");
        return -1;
    }
    while (args[j] != NULL) {
        if (is_good_type(args[j]) == -1)
            return -1;
        j += 2;
    }
    return 0;
}
