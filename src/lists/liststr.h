#ifndef SRC_LISTSTR_H
#define SRC_LISTSTR_H

#include <stdio.h>
#include "list.h"

List* new_str_list(size_t size);
void push_str_list(List* list, char* element);
void free_str_list(List* list);

#endif
