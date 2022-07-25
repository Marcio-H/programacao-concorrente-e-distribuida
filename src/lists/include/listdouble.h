#ifndef NEXTNEIGHBOR_LISTDOUBLE_H
#define NEXTNEIGHBOR_LISTDOUBLE_H

#include <stdio.h>
#include "list.h"

List* new_double_list(size_t size);
void push_value_to_double_list(List* list, double value);
void free_double_list(List* list);
double get_value_from_double_list(List* list, size_t index);
size_t get_size_from_double_list(List* list);
void push_value_to_index_double_list(List* list, double value, size_t index);
double* get_vector_from_double_list(List* list);

#endif
