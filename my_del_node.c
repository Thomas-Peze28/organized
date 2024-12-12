/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Organized
*/

#include "include/my.h"
#include "include/bootstrap.h"
#include "libshell/shell.h"

int del_handling(void *data, char **args)
{
    int i = 0;
    int j = 0;

    while (args[i] != NULL) {
        if (my_atoi(args[i]) >= count_nodes(data)) {
            my_printf("ID : %d isn't in list\n", my_atoi(args[i]));
            return -1;
        }
        i++;
    }
    while (args[j] != NULL) {
        if (my_atoi(args[j]) >= count_nodes(data)) {
            my_printf("ID : %d isn't in list\n", my_atoi(args[j]));
            return -1;
        }
        j++;
    }
    return 0;
}

int del(void *data, char **args)
{
    linked_list_t *storage = ((linked_list_t *)data);
    linked_list_t *temp = storage;
    linked_list_t *prev = temp;
    int i = 0;

    if (del_handling(data, args) == -1)
        return 0;
    while (args[i] != NULL) {
        while (temp != NULL && temp->id != my_atoi(args[i])) {
            prev = temp;
            temp = temp->next;
        }
        my_printf("%s n°%d - \"%s\" deleted\n"
            , temp->type, temp->id, temp->name);
        prev->next = temp->next;
        free(temp);
        i++;
    }
    return 0;
}
