#include <stdlib.h>
#include "liststr.h"

struct list {
    char** array;
    size_t used;
    size_t size;
};

List* new_str_list(size_t size) {
    List* list = malloc(sizeof list);

    list->array = malloc(size * sizeof(char));
    list->used = 0;
    list->size = size;
    return list;
}

void push_str_list(List* list, char* element) {
    if (list->used == list->size) {
        list->size += INCREMENT_SIZE;
        list->array = realloc(list->array, list->size * sizeof(char));
    }
    list->array[list->used++] = element;
}

void free_str_list(List* list) {
    free(list->array);
    free(list);
}
