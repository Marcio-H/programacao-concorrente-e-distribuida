#include <stdlib.h>
#include "listfloat.h"

struct list {
    float *array;
    size_t used;
    size_t size;
};

List* new_float_list(size_t size) {
    List* list = malloc(sizeof list);

    list->array = malloc(size * sizeof(float));
    list->used = 0;
    list->size = size;
    return list;
}

void push_float_list(List* list, float element) {
    if (list->used == list->size) {
        list->size += INCREMENT_SIZE;
        list->array = realloc(list->array, list->size * sizeof(float));
    }
    list->array[list->used++] = element;
}

void free_float_list(List* list) {
    free(list->array);
    free(list);
}

float get_value_from_float_list(List* list, size_t index) {
    return list->array[index];
}