#include "plummet_map_functions.h"

PLUMMET_VARIABLE plummet_make_map() {
    PLUMMET_MAP *map = malloc(sizeof(PLUMMET_MAP));
    map->head = NULL;
    map->tail = NULL;
    map->size = 0;
    return make_plummet_var(map);
}

void plummet_map_insert(
    PLUMMET_VARIABLE *var_map,
    PLUMMET_VARIABLE *key,
    PLUMMET_VARIABLE *value
) {
    if (var_map->type != PLUMMET_TYPE_MAP) {
        perror("plummet_map_insert() called on non-map variable\n");
        exit(1);
    }
    
    PLUMMET_MAP *map = var_map->value.map;

    // Check if key already exists, if so, update value
    PLUMMET_MAP_NODE *temp_node = map->head;
    while (temp_node != NULL) {
        if (plummet_variable_equals(*(temp_node->key), *key)) {
            temp_node->value = value;
            return;
        }
        temp_node = temp_node->next;
    }

    PLUMMET_MAP_NODE *node = malloc(sizeof(PLUMMET_MAP_NODE));
    node->key = key;
    node->value = value;
    node->next = NULL;

    if (map->head == NULL) {
        map->head = node;
        map->tail = node;
    } else {
        map->tail->next = node;
        map->tail = node;
    }

    map->size++;
}

PLUMMET_VARIABLE *plummet_map_get(
    PLUMMET_VARIABLE *var_map,
    PLUMMET_VARIABLE *key
) {
    if (var_map->type != PLUMMET_TYPE_MAP) {
        perror("plummet_map_insert() called on non-map variable\n");
        exit(1);
    }

    PLUMMET_MAP *map = var_map->value.map;    

    PLUMMET_MAP_NODE *node = map->head;
    while (node != NULL) {
        if (plummet_variable_equals(*(node->key), *key)) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

bool plummet_map_remove(
    PLUMMET_VARIABLE *var_map,
    PLUMMET_VARIABLE *key
) {
    if (var_map->type != PLUMMET_TYPE_MAP) {
        perror("plummet_map_insert() called on non-map variable\n");
        exit(1);
    }
    
    PLUMMET_MAP *map = var_map->value.map;

    PLUMMET_MAP_NODE *node = map->head;
    PLUMMET_MAP_NODE *prev = NULL;
    while (node != NULL) {
        if (plummet_variable_equals(*(node->key), *key)) {
            if (prev == NULL) {
                map->head = node->next;
            } else {
                prev->next = node->next;
            }
            free(node);
            map->size--;
            return true;
        }
        prev = node;
        node = node->next;
    }
    return false;
}