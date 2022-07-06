#include <stdlib.h>
#include "listdouble.h"

struct list {
    double* array;
    size_t used;
    size_t size;
};

List* new_double_list(size_t size) {
    List* list = malloc(sizeof list);

    list->array = malloc(size * sizeof(double));
    list->used = 0;
    list->size = size;
    return list;
}

void push_double_list(List* list, double element) {
    if (list->used == list->size) {
        list->size += INCREMENT_SIZE;
        list->array = realloc(list->array, list->size * sizeof(double));
    }
    list->array[list->used++] = element;
}

void free_double_list(List* list) {
    free(list->array);
    free(list);
}

double get_value_from_double_list(List* list, size_t index) {
    return list->array[index];
}