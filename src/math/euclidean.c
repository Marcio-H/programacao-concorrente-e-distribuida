#include <math.h>
#include "euclidean.h"

double distance(List* l1, List* l2) {
    double sum = 0;
    size_t lenght = get_size_from_double_list(l1);

    for (int i = 0; i < lenght; ++i) {
        const double subtract = get_value_from_double_list(l1, i) - get_value_from_double_list(l2, i);

        sum += subtract * subtract;
    }
    return sqrt(sum);
}

double distance_parallel(List* l1, List* l2) {
    size_t lenght = get_size_from_double_list(l1);
    double sum, subtract;
    int i;

    #pragma omp parallel for if(lenght > 50) default(none) shared(lenght, l1, l2, sum) private(subtract, i)
    for (i = 0; i < lenght; i++) {
        subtract = get_value_from_double_list(l1, i) - get_value_from_double_list(l2, i);
        #pragma omp critical(sum_euclidian)
        sum += subtract * subtract;
    }
    return sqrt(sum);
}

double self_distance(List* list, size_t beginning_sub_list_one, size_t beginning_sub_list_two, size_t size_lists)
{
    double subtract, sum = 0;

    for (; size_lists > 0; --size_lists, ++beginning_sub_list_one, ++beginning_sub_list_two) {
        subtract = get_value_from_double_list(list, beginning_sub_list_two) - get_value_from_double_list(list, beginning_sub_list_one);
        sum += subtract * subtract;
    }
    return sqrt(sum);
}
