/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Organized
*/

#include "include/my.h"
#include "include/bootstrap.h"
#include "libshell/shell.h"

void swap_node(LIST **storage, LIST *temp, LIST *next, LIST *prev)
{
    if (prev == NULL) {
        *storage = next;
    } else {
        prev->next = next;
    }
    temp->next = next->next;
    next->next = temp;
}

void travel_nodes(LIST **storage)
{
    LIST *temp = *storage;
    LIST *next;
    LIST *prev = NULL;

    while (temp != NULL && temp->next != NULL) {
        next = temp->next;
        if (temp->id < next->id) {
            swap_node(storage, temp, next, prev);
            prev = next;
            temp = next->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

int sort(void *data, char **args)
{
    LIST *storage = (LIST *)data;
    int node_count = count_nodes(storage);

    if (storage == NULL || storage->next == NULL)
        return 0;
    for (int i = 0; i < node_count; i++) {
        travel_nodes(&storage);
        data = storage;
    }
    my_printf("Résultat final:\n");
    disp(data);
    return 0;
}
