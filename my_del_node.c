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
    int j = 0;

    while (args[j] != NULL) {
        if (my_atoi(args[j]) >= count_nodes(data)) {
            my_printf("ID : %d isn't in list\n", my_atoi(args[j]));
            return -1;
        }
        if (my_atoi(args[j]) == ((linked_list_t *)data)->id) {
            my_printf("Cannot delete the first node\n");
            return -1;
        }
        j++;
    }
    return 0;
}

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
    linked_list_t *storage = ((linked_list_t *)data);
    linked_list_t *temp = storage;
    linked_list_t *prev = NULL;
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
