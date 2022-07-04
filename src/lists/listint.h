#ifndef SRC_ARRAYINT_H
#define SRC_ARRAYINT_H

#include <stdio.h>
#include "list.h"

List* new_integer_list(size_t size);
void push_integer_list(List* list, int element);
void free_integer_list(List* list);

#endif