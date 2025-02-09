/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Organized
*/

#include "include/my.h"
#include "include/bootstrap.h"
#include "libshell/shell.h"

void sort_name(linked_list_t **storage)
{
    linked_list_t *temp = *storage;
    linked_list_t *next = NULL;

    while (temp != NULL && temp->next != NULL) {
        next = temp->next;
        if (my_strcmp(temp->name, next->name) > 0) {
            swap_node(temp, next);
        }
        temp = temp->next;
    }
}

void sort_name_r(linked_list_t **storage)
{
    linked_list_t *temp = *storage;
    linked_list_t *next = NULL;

    while (temp != NULL && temp->next != NULL) {
        next = temp->next;
        if (my_strcmp(temp->name, next->name) < 0) {
            swap_node(temp, next);
        }
        temp = temp->next;
    }
}
