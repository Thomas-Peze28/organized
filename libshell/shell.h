/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H

int count_nodes(void *data);
linked_list_t *create_new_node(linked_list_t *storage, char *type, char *name);
void init_first_node(linked_list_t *storage, linked_list_t *new_node);
void add_to_end(linked_list_t *storage, linked_list_t *new_node);

// To be implemented
int add(void *data, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data);

// Already implemented
int workshop_shell(void *data);

#endif /* SHELL_H */
