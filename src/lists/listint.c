#include <stdlib.h>
#include "listint.h"

struct list{
    int *array;
    size_t used;
    size_t size;
};

List* new_integer_list(size_t size) {
    List* list = malloc(sizeof list);

    list->array = malloc(size * sizeof(int));
    list->used = 0;
    list->size = size;
    return list;
}

void push_integer_list(List *list, int element) {
    if (list->used == list->size) {
        list->size += INCREMENT_SIZE;
        list->array = realloc(list->array, list->size * sizeof(int));
    }
    list->array[list->used++] = element;
}

void free_integer_list(List* list) {
    free(list->array);
    free(list);
}

int get_value_from_integer_list(List* list, size_t index) {
    return list->array[index];
}
