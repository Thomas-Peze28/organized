/*
** EPITECH PROJECT, 2024
** organized
** File description:
** count_nodes
*/

#include "include/my.h"
#include "include/bootstrap.h"
#include "libshell/shell.h"

int count_nodes(void *data)
{
    linked_list_t *storage = ((linked_list_t *)data);
    linked_list_t *temp = storage;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
