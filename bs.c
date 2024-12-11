/*
** EPITECH PROJECT, 2024
** bs
** File description:
** Organized Bootstrap functions
*/
#include "include/my.h"
#include "include/bootstrap.h"

int print_typed_value(void *data, type_t type)
{
    if (type == CHAR) {
        write(1, data, sizeof(char));
        my_putchar('\n');
    }
    if (type == STRING) {
        my_putstr(data);
        my_putchar('\n');
    }
    if (type == INTEGER) {
        my_put_nbr(*(int *)data);
        my_putchar('\n');
    }
    if (type == PLAYER) {
        printf("%s: lvl.%d\n",
            ((player_t *)data)->name, ((player_t *)data)->lvl);
    }
    return 0;
}

void push_to_list(linked_list_t **begin, void *data)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t) + 1);
    linked_list_t *temp = *begin;

    new_node->name = data;
    new_node->next = NULL;
    if ((*begin) == NULL) {
        (*begin) = new_node;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void display_list(linked_list_t *begin, void(*disp_fct)())
{
    linked_list_t *temp = begin;

    while (temp != NULL) {
        disp_fct(temp->name);
        temp = temp->next;
    }
}

void display(void *data)
{
    printf("%d\n", *(int *)data);
}
