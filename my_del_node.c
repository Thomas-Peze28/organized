/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Organized
*/

#include "include/my.h"
#include "include/bootstrap.h"
#include "libshell/shell.h"

int delete_node(LIST **storage, LIST *prev, LIST *temp)
{
    my_printf("%s n°%d - \"%s\" deleted\n", temp->type, temp->id, temp->name);
    if (prev == NULL) {
        *storage = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    return 0;
}

int del(void *data, char **args)
{
    linked_list_t **storage = (linked_list_t **)data;
    linked_list_t *temp;
    linked_list_t *prev;
    int i = 0;

    if (del_handling(data, args) == 84)
        return 84;
    while (args[i] != NULL) {
        temp = *storage;
        prev = NULL;
        while (temp != NULL && temp->id != my_atoi(args[i])) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL) {
            delete_node(storage, prev, temp);
        }
        i++;
    }
    return 0;
}
