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
    return 84;
}

int count_args(char **args)
{
    int i = 0;
    int count_args = 0;

    while (args[i] != NULL) {
        count_args++;
        i++;
    }
    return count_args;
}

int add_handling(void *data, char **args)
{
    int j = 0;
    int count_arg = count_args(args);

    if (count_arg == 0)
        return 84;
    if ((count_arg % 2) != 0) {
        my_printf("It must be a pair number of argument\n");
        return 84;
    }
    while (args[j] != NULL) {
        if (is_good_type(args[j]) == 84)
            return 84;
        j += 2;
    }
    return 0;
}

int del_handling(void *data, char **args)
{
    linked_list_t **storage = (linked_list_t **)data;
    int j = 0;

    if (count_args(args) == 0)
        return 84;
    while (args[j] != NULL) {
        if (my_atoi(args[j]) >= count_nodes(*storage)) {
            my_printf("ID : %d isn't in list\n", my_atoi(args[j]));
            return 84;
        }
        j++;
    }
    return 0;
}
