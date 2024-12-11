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
        printf("DEBUG : %s n°%d - \"%s\"\n", list->type, list->id, list->name);
        list = list->next;
    }
}

int del(void *data, char **args)
{
    linked_list_t *storage = ((linked_list_t *)data);
    linked_list_t *temp = storage;
    int i = 0;

    if (storage->next == NULL) {
        free(storage);
        return 0;
    }
    while (args[i] != NULL) {
        printf("ID RECHERCHE : %d\n", my_atoi(args[i]));
        while (temp->next != NULL) {
            temp = temp->next;
        }
        i++;
    }
    return 0;
}

int sort(void *data, char **args)
{
    return 0;
}

int disp(void *data)
{
    linked_list_t *temp = ((linked_list_t *)data);

    while (temp != NULL && temp->type != NULL) {
        printf("%s n°%d - \"%s\"\n", temp->type, temp->id, temp->name);
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
