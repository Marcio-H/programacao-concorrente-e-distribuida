#include<stdio.h>
#include<math.h>
#include "../lists/include/listint.h"

int main(int argc, char const *argv[])
{
    int tamanhoVetor = 13;
    int tamanhoSequencia = 4;
    float total = 0;

    int vetor1[13] = {0, 1, 3, 2, 9, 1, 14, 15, 1, 2, 2, 10, 7};
    
    //Percorre o vetor em sequências de 4 valores.
    for (int i = 0; i <= tamanhoVetor - tamanhoSequencia; i++) {
        printf("\n\n ==");
        for (int ii = 0; ii <= tamanhoVetor - tamanhoSequencia; ii++) {
            printf("\n");
            for(int c = 0; c < tamanhoSequencia; c++) {
                printf("\nI: %d - II: %d", vetor1[i+c], vetor1[ii+c]);
            }
        }

    }
    
    return 0;
}