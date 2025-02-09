/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Organized
*/

#include "include/my.h"
#include "include/bootstrap.h"
#include "libshell/shell.h"

void swap_node(linked_list_t *a, linked_list_t *b)
{
    int temp_id = a->id;
    char *temp_type = a->type;
    char *temp_name = a->name;

    a->id = b->id;
    a->type = b->type;
    a->name = b->name;
    b->id = temp_id;
    b->type = temp_type;
    b->name = temp_name;
}

void sort_id(linked_list_t **storage)
{
    linked_list_t *temp = *storage;
    linked_list_t *next = NULL;

    while (temp != NULL && temp->next != NULL) {
        next = temp->next;
        if (temp->id > next->id) {
            swap_node(temp, next);
        }
        temp = temp->next;
    }
}

void sort_id_r(linked_list_t **storage)
{
    linked_list_t *temp = *storage;
    linked_list_t *next = NULL;

    while (temp != NULL && temp->next != NULL) {
        next = temp->next;
        if (temp->id < next->id) {
            swap_node(temp, next);
        }
        temp = temp->next;
    }
}
