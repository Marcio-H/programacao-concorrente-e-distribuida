#ifndef SRC_ARRAYFLOAT_H
#define SRC_ARRAYFLOAT_H

#include <stdio.h>
#include "list.h"

List* new_float_list(size_t size);
void push_float_list(List* list, float element);
void free_float_list(List* list);
float get_value_from_float_list(List* list, size_t index);

#endif