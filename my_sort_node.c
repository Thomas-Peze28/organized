/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Organized
*/

#include "include/my.h"
#include "include/bootstrap.h"
#include "libshell/shell.h"


int sort(void *data, char **args)
{
    linked_list_t *storage = ((linked_list_t *)data);
    linked_list_t *temp = storage;
    linked_list_t *prev = temp;

    for (int i = 0; i < count_nodes(data); i++) {
        while (temp != NULL &&
            temp->next != NULL && temp->next->id < temp->id) {
            prev = temp;
            temp = temp->next;
        }
        my_printf("PREV : %d\n", prev->id);
        my_printf("TEMP : %d\n", temp->id);
        my_printf("SUIV : %d\n", temp->next->id);
    }
    return 0;
}
