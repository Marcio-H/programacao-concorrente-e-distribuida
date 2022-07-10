#include <math.h>
#include "euclidean.h"

double distance(double* vector_one, double* vector_two, size_t distance)
{
    double subtract, sum = 0;

    for (; distance > 0; --distance, ++vector_one, ++vector_two) {
        subtract = *vector_one - *vector_two;
        sum += subtract * subtract;
    }
    return sqrt(sum);
}

double distance_parallel(double* vector_one, double* vector_two, size_t distance)
{
    double subtract, sum = 0;
    int i;

    #pragma omp parallel for if (distance > 300) default(none) private(subtract) shared(distance, vector_one, vector_two, sum)
    for (i = 0; i < distance; i++) {
        subtract = vector_one[i] - vector_two[i];
        #pragma omp atomic
        sum += subtract * subtract;
    }
    return sqrt(sum);
}
