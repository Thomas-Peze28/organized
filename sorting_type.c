/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Organized
*/

#include "include/my.h"
#include "include/bootstrap.h"
#include "libshell/shell.h"

void sort_type(linked_list_t **storage)
{
    linked_list_t *temp = *storage;
    linked_list_t *next = NULL;

    while (temp != NULL && temp->next != NULL) {
        next = temp->next;
        if (my_strcmp(temp->type, next->type) > 0) {
            swap_node(temp, next);
        }
        temp = temp->next;
    }
}

void sort_type_r(linked_list_t **storage)
{
    linked_list_t *temp = *storage;
    linked_list_t *next = NULL;

    while (temp != NULL && temp->next != NULL) {
        next = temp->next;
        if (my_strcmp(temp->type, next->type) < 0) {
            swap_node(temp, next);
        }
        temp = temp->next;
    }
}
