/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Organized
*/

#include "include/my.h"
#include "include/bootstrap.h"
#include "libshell/shell.h"

int sort_id_choice(linked_list_t **storage, char **args, int node_count)
{
    if (count_args(args) == 2 && my_strcmp(args[0], "ID") == 0
        && my_strcmp(args[1], "-r") == 0) {
        for (int i = 0; i < node_count; i++) {
            sort_id_r(storage);
        }
        return 0;
    }
    if (count_args(args) == 1 && my_strcmp(args[0], "ID") == 0) {
        for (int i = 0; i < node_count; i++) {
            sort_id(storage);
        }
        return 0;
    }
    return 0;
}

int sort_name_choice(linked_list_t **storage, char **args, int node_count)
{
    if (count_args(args) == 2 && my_strcmp(args[0], "NAME") == 0
        && my_strcmp(args[1], "-r") == 0) {
        for (int i = 0; i < node_count; i++) {
            sort_name_r(storage);
        }
        return 0;
    }
    if (count_args(args) == 1 && my_strcmp(args[0], "NAME") == 0) {
        for (int i = 0; i < node_count; i++) {
            sort_name(storage);
        }
        return 0;
    }
    return 0;
}

int sort_type_choice(linked_list_t **storage, char **args, int node_count)
{
    if (count_args(args) == 2 && my_strcmp(args[0], "TYPE") == 0
        && my_strcmp(args[1], "-r") == 0) {
        for (int i = 0; i < node_count; i++) {
            sort_type_r(storage);
        }
        return 0;
    }
    if (count_args(args) == 1 && my_strcmp(args[0], "TYPE") == 0) {
        for (int i = 0; i < node_count; i++) {
            sort_type(storage);
        }
        return 0;
    }
    return 0;
}

int sort(void *data, char **args)
{
    LIST **storage = (LIST **)data;
    int node_count = count_nodes(*storage);

    if (*storage == NULL || (*storage)->next == NULL)
        return 0;
    sort_id_choice(storage, args, node_count);
    sort_name_choice(storage, args, node_count);
    sort_type_choice(storage, args, node_count);
    return 0;
}
