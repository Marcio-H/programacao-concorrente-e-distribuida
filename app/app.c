#include <stdio.h>
#include <stdlib.h>
#include "listdouble.h"

List* read_from_file(char* file_path);

int main(int argc, char *argv[])
{
    List* number = read_from_file(argv[1]);

    for (int i = 0; i < size(number); ++i) {
        printf("%.2f\n", get_value_from_double_list(number, i));
    }

    return EXIT_SUCCESS;
}

List* read_from_file(char* file_path) {
    FILE *arqin;
    char* line;
    List* numbers = new_double_list(10);

    arqin = fopen(file_path, "r");
    if (arqin == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        exit(EXIT_FAILURE);
    }
    while (!feof(arqin))
    {
        fgets(line, 100, arqin);
        printf("Colocando valor %s", line);
        push_double_list(numbers, atof(line));
    }
    fclose(arqin);
    return numbers;
}





//   FILE  *arqout;
//    // Abre um arquivo no modo gravacao
//    arqout = fopen("mp.txt","w");
//    if(arqout == NULL)
//    {
//        printf("Error na abertura do arquivo de saida");
//        exit(1);
//    }
//    fclose(arqout);