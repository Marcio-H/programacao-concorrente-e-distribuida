#ifndef NEXTNEIGHBOR_DISTANCIA_EUCLIDIANA_H
#define NEXTNEIGHBOR_DISTANCIA_EUCLIDIANA_H

#include "listdouble.h"

double distance(List* l1, List* l2);
double distance_parallel(List* l1, List* l2);
double self_distance(List* list, size_t beginning_sub_list_one, size_t beginning_sub_list_two, size_t size_lists);

#endif
