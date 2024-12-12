/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Organized
*/

#include "include/my.h"
#include "include/bootstrap.h"
#include "libshell/shell.h"

void disp_debug(linked_list_t *list)
{
    while (list != NULL) {
        my_printf("DEBUG : %s n°%d - \"%s\"\n"
            , list->type, list->id, list->name);
        list = list->next;
    }
}

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
        printf("PREV : %d\n", prev->id);
        printf("TEMP : %d\n", temp->id);
        printf("SUIV : %d\n", temp->next->id);
    }
    return 0;
}

int disp(void *data)
{
    linked_list_t *temp = ((linked_list_t *)data);

    while (temp != NULL && temp->type != NULL) {
        my_printf("%s n°%d - \"%s\"\n", temp->type, temp->id, temp->name);
        temp = temp->next;
    }
    return 0;
}

int main(void)
{
    linked_list_t *storage = malloc(sizeof(linked_list_t));

    workshop_shell(storage);
    return 0;
}
