#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include "listdouble.h"
#include "listint.h"
#include "euclidean.h"

typedef struct data {
    List* indexes;
    List* values;
    size_t subsequence;
    size_t used; //trocar nome dessa variavel
} Data;

List* read_from_file(char* file_path);
void send_numbers(List* numbers);
List* receive_numbers();
Data* new_data(List* numbers, size_t subsequence);
void write_report(Data* data);
void process_euclidean_data(List* numbers, Data* data);
int begin_iterator(size_t size);
int end_iterator(size_t size);

int ranks_size;
int rank;

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &ranks_size);
    MPI_Comm_rank(MPI_COMM_WORLD, & rank);

    List* numbers;

    if (rank == 0) {
        numbers = read_from_file(argv[2]);
        send_numbers(numbers);
    } else {
        numbers = receive_numbers(numbers);
    }

    Data* data = new_data(numbers, atoi(argv[1]));

    process_euclidean_data(numbers, data);
    write_report(data);
    MPI_Finalize();
    free_double_list(numbers);
    free_double_list(data->values);
    free_integer_list(data->indexes);
    free(data);
    return EXIT_SUCCESS;
}

List* read_from_file(char* file_path)
{
    FILE *arqin;
    char* line;
    List* numbers = new_double_list(10);

    arqin = fopen(file_path, "r");
    if (arqin == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        exit(EXIT_FAILURE);
    }
    line = malloc(100 * sizeof(char));
    while (!feof(arqin))
    {
        fgets(line, 100, arqin);
        push_value_to_double_list(numbers, atof(line));
    }
    fclose(arqin);
    free(line);
    return numbers;
}

void send_numbers(List* numbers)
{
    int size = get_size_from_double_list(numbers);
    MPI_Bcast(&size, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(get_vector_from_double_list(numbers), size, MPI_DOUBLE, 0, MPI_COMM_WORLD);
}

List* receive_numbers()
{
    int size;
    double* array;

    MPI_Bcast(&size, 1, MPI_INT, 0, MPI_COMM_WORLD);
    array = malloc(sizeof (double) * size);
    MPI_Bcast(array, size, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    return new_double_list_with_array(size, array);
}

Data* new_data(List* numbers, size_t subsequence)
{
    Data* data = malloc(sizeof(Data));
    size_t data_size = get_size_from_double_list(numbers) - subsequence + 1;

    data->values = new_double_list(data_size);
    data->indexes = new_integer_list(data_size);
    data->subsequence = subsequence;
    data->used = data_size;
    return data;
}

void process_euclidean_data(List* numbers, Data* data)
{
    int i, j, smaller_index;
    double smaller_value, value;
    int init = begin_iterator(data->used);
    int end = end_iterator(data->used);

    #pragma omp parallel for default(none) shared(data, numbers, ranks_size, rank, init, end) private(smaller_value, smaller_index, j, value)
    for (i = init; i < end; ++i)
    {
        smaller_value = 9999;
        for (j = 0; j < data->used; ++j)
        {
            if (i == j)
            {
                continue;
            }
            double* vector_one = get_vector_from_double_list(numbers) + i;
            double* vector_two = get_vector_from_double_list(numbers) + j;

            value = distance(vector_one, vector_two, data->subsequence);
            if (value < smaller_value)
            {
                smaller_value = value;
                smaller_index = j;
            }
        }
        #pragma omp critical(add)
        {
            push_value_to_index_integer_list(data->indexes, smaller_index + 1, i);
            push_value_to_index_double_list(data->values, smaller_value, i);
        }
    }
}

void write_report(Data* data)
{
    FILE  *arqout;
    int i, j;
    int init = begin_iterator(data->used);
    int end = end_iterator(data->used);

    for (j = 0; j < ranks_size; ++j)
    {
        if (rank == j)
        {
            arqout = fopen(RESOURCE_OUTPUT_PATH,rank == 0 ? "w" : "a");
            if(arqout == NULL)
            {
                printf("Error na abertura do arquivo de saida");
                exit(1);
            }
            for (i = init; i < end; ++i)
            {
                fprintf(arqout,"%d - %f\n", get_value_from_integer_list(data->indexes, i), get_value_from_double_list(data->values, i));
            }
            fclose(arqout);
        }
        MPI_Barrier(MPI_COMM_WORLD);
    }
}

int begin_iterator(size_t size) {
    return (size / ranks_size) * rank;
}

int end_iterator(size_t size) {
    int i = (size / ranks_size) * (rank + 1);

    return rank == (ranks_size - 1) ? i + (size % ranks_size) : i;
}