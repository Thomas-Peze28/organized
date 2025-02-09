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

int disp(void *data)
{
    linked_list_t **storage = (linked_list_t **)data;
    linked_list_t *temp = *storage;

    while (temp != NULL && temp->type != NULL) {
        my_printf("%s n°%d - \"%s\"\n", temp->type, temp->id, temp->name);
        temp = temp->next;
    }
    return 0;
}

int main(void)
{
    linked_list_t *storage = malloc(sizeof(linked_list_t));

    if (storage == NULL)
        return 84;
    storage->id = 0;
    storage->type = NULL;
    storage->name = NULL;
    storage->next = NULL;
    if (workshop_shell((void *)&storage) == 84)
        return 84;
    return 0;
}
