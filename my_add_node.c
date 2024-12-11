/*
** EPITECH PROJECT, 2024
** organized
** File description:
** adding nodes
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

linked_list_t *create_new_node(linked_list_t *storage, char *type, char *name)
{
    linked_list_t *new_node = malloc(sizeof(linked_list_t));

    if (new_node == NULL) {
        return NULL;
    }
    new_node->id = count_nodes(storage);
    new_node->type = my_strdup(type);
    new_node->name = my_strdup(name);
    new_node->next = NULL;
    return new_node;
}

void init_first_node(linked_list_t *storage, linked_list_t *new_node)
{
    storage->id = 0;
    storage->type = new_node->type;
    storage->name = new_node->name;
    storage->next = NULL;
    printf("%s n°0 - \"%s\" added.\n", new_node->type, new_node->name);
}

void add_to_end(linked_list_t *storage, linked_list_t *new_node)
{
    linked_list_t *temp = storage;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

int add(void *data, char **args)
{
    linked_list_t *storage = (linked_list_t *)data;
    linked_list_t *new_node;
    int i = 0;

    while (args[i] != NULL && args[i + 1] != NULL) {
        new_node = create_new_node(storage, args[i], args[i + 1]);
        if (new_node == NULL) {
            return -1;
        }
        if (storage->type == NULL) {
            init_first_node(storage, new_node);
        } else {
            add_to_end(storage, new_node);
            printf("%s n°%d - \"%s\" added.\n"
                , new_node->type, new_node->id, new_node->name);
        }
        i += 2;
    }
    return 0;
}
