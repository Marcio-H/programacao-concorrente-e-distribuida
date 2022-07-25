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

List* new_double_list_with_array(size_t size, double* array) {
    List* list = malloc(sizeof list);

    list->array = array;
    list->used = size;
    list->size = size;
    return list;
}

void push_value_to_double_list(List* list, double value) {
    if (list->used == list->size) {
        list->size += INCREMENT_SIZE;
        list->array = realloc(list->array, list->size * sizeof(double));
    }
    list->array[list->used++] = value;
}

void free_double_list(List* list) {
    free(list->array);
    free(list);
}

double get_value_from_double_list(List* list, size_t index) {
    return list->array[index];
}

size_t get_size_from_double_list(List* list) {
    return list->used;
}

void push_value_to_index_double_list(List* list, double value, size_t index)
{
    list->array[index] = value;
    list->used++;
}

double* get_vector_from_double_list(List* list)
{
    return list->array;
}
