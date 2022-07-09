#include <stdio.h>
#include <stdlib.h>
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
Data* new_data(List* numbers, size_t subsequence);
void write_report(List* indexes, List* values);
void process_euclidean_data(List* numbers, Data* data);

int main(__attribute__((unused)) int argc, char *argv[])
{
    List* numbers = read_from_file(argv[2]);
    Data* data = new_data(numbers, atoi(argv[1]));

    process_euclidean_data(numbers, data);
    write_report(data->indexes, data->values);
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

    for (i = 0; i < data->used; ++i)
    {
        smaller_value = 9999;
        for (j = 0; j < data->used; ++j)
        {
            if (i != j)
            {
                value = self_distance(numbers, i, j, data->subsequence);
                if (value < smaller_value)
                {
                    smaller_value = value;
                    smaller_index = j;
                }
            }
        }
        push_value_to_integer_list(data->indexes, smaller_index + 1);
        push_value_to_double_list(data->values, smaller_value);
    }
}

void write_report(List* indexes, List* values)
{
    FILE  *arqout;

    arqout = fopen("/home/marcio/dev/git/programacao-concorrente-e-distribuida/resources/output.txt","w"); //arrumar isso
    if(arqout == NULL)
    {
        printf("Error na abertura do arquivo de saida");
        exit(1);
    }
//    fazer funções
    for (int i = 0; i < get_size_from_integer_list(indexes); ++i)
    {
        fprintf(arqout,"%d - %f\n", get_value_from_integer_list(indexes, i), get_value_from_double_list(values, i));
    }
    fclose(arqout);
}
