#ifndef SRC_ARRAYINT_H
#define SRC_ARRAYINT_H

#include <stdio.h>
#include "list.h"

List* new_integer_list(size_t size);
void push_value_to_integer_list(List* list, int value);
void free_integer_list(List* list);
int get_value_from_integer_list(List* list, size_t index);
size_t get_size_from_integer_list(List* list);
void push_value_to_index_integer_list(List* list, int value, size_t index);

#endif