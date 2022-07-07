#include <omp.h>
#include <math.h>
#include "euclidean.h"


double distance(List* l1, List* l2) {
    double sum = 0;
    size_t lenght = size(l1);

    for (int i = 0; i < lenght; ++i) {
        const double subtract = get_value_from_double_list(l1, i) - get_value_from_double_list(l2, i);
        sum += subtract * subtract;
    }
    return sqrt(sum);
}

double distance_parallel(List* l1, List* l2) {
    size_t lenght = size(l1);
    double sum;

    #pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < lenght; i++) {
        const double subtract = get_value_from_double_list(l1, i) - get_value_from_double_list(l2, i);

        sum = subtract * subtract;
    }
    return sqrt(sum);
}
