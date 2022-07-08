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

//Muito cuidado ao usar este metodo, uma sublista não deve chamar os metodos push e free;
List* sub_list(List* list, size_t from, size_t to) {
    List* new_list = malloc(sizeof list);

    new_list->array = list->array + from;
    new_list->used = to - from;
    return new_list;
}
