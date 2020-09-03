/*
** EPITECH PROJECT, 2020
** test
** File description:
** main
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "functions.h"
#include "my.h"

void add_free_list(void *p)
{
    free_list_t *node = (*FREE_LIST);

    while (node->next != NULL)
        node = node->next;
    node->next = malloc(sizeof(free_list_t));
    node->next->p = p;
    node->next->next = NULL;
}

void print_list(void)
{
    free_list_t *node = (*FREE_LIST);

    while (node != NULL) {
        node = node->next;
    }
}

int get_list_size(void)
{
    free_list_t *node = (*FREE_LIST);
    int i = 0;

    while (node != NULL) {
        i++;
        node = node->next;
    }
    return (i);
}

void free_all_list(void)
{
    free_list_t *node = (*FREE_LIST);
    free_list_t *p_node;

    while (node->next != NULL) {
        p_node = node;
        node = node->next;
        free(p_node->p);
        free(p_node);
    }
    free(node->p);
    free(node);
    free(FREE_LIST);
}