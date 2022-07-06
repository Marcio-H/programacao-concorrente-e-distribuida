#ifndef NEXTNEIGHBOR_LISTDOUBLE_H
#define NEXTNEIGHBOR_LISTDOUBLE_H

#include <stdio.h>
#include "list.h"

List* new_double_list(size_t size);
void push_double_list(List* list, double element);
void free_double_list(List* list);
double get_value_from_double_list(List* list, size_t index);

#endif
