#include "plummet_list_functions.h"

PLUMMET_VARIABLE plummet_make_list() {
    PLUMMET_LIST *list = malloc(sizeof(PLUMMET_LIST));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return make_plummet_variable_list(list);
}

void plummet_list_push(
    PLUMMET_VARIABLE *list,
    PLUMMET_VARIABLE *value
) {
    if (list->type != PLUMMET_TYPE_LIST) {
        perror("plummet_list_push() called on non-list variable\n");
        exit(1);
    }

    PLUMMET_LIST *l = list->value.list;

    PLUMMET_LIST_NODE *node = malloc(sizeof(PLUMMET_LIST_NODE));
    node->value = value;
    node->next = NULL;

    if (l->head == NULL) {
        l->head = node;
        l->tail = node;
    } else {
        l->tail->next = node;
        l->tail = node;
    }

    l->size++;
}

PLUMMET_VARIABLE *plummet_list_at(
    PLUMMET_VARIABLE *list,
    int index
) {
    if (list->type != PLUMMET_TYPE_LIST) {
        perror("plummet_list_at() called on non-list variable\n");
        exit(1);
    }

    PLUMMET_LIST *l = list->value.list;
    
    if (index < 0 || index >= l->size) {
        return NULL;
    }

    PLUMMET_LIST_NODE *node = l->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }

    PLUMMET_VARIABLE *temp = node->value; // MIGHT BE USELESS
    return temp;
}

bool plummet_list_remove(
    PLUMMET_VARIABLE *list,
    int index
) {
    if (list->type != PLUMMET_TYPE_LIST) {
        perror("plummet_list_remove() called on non-list variable\n");
        exit(1);
    }

    PLUMMET_LIST *l = list->value.list;
    
    if (index < 0 || index >= l->size) {
        return false;
    }
    PLUMMET_LIST_NODE *node = l->head;
    if (index == 0) {
        l->head = node->next;
        free(node);
        l->size--;
        return true;
    }
    for (int i = 0; i < index - 1; i++) {
        node = node->next;
    }
    PLUMMET_LIST_NODE *temp = node->next;
    node->next = temp->next;
    free(temp);
    l->size--;
    return true;
}