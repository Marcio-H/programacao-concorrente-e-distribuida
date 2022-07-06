// ************************************************************
//   Exemplo de uso de arquivo texto
//   Este programa lê um arquivo texto e imprime o seu
//   conteudo na tela.
// ************************************************************
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]);

void main(int argc, char *argv[])
{
  FILE *arqin, *arqout;
  char linha[100];
  char *result;
  double *numbers;
  int i;

  numbers = (double*)malloc(100 * sizeof(double));

  // Abre um arquivo no modo leitura
  arqin = fopen(argv[1], "rt");
  if (arqin == NULL)    {
     printf("Erro na abertura do arquivo\n");
     return;
  }

   // Abre um arquivo no modo gravacao
   arqout = fopen("mp.txt","w");
   if(arqout == NULL)
   {
      printf("Error na abertura do arquivo de saida");   
      exit(1);             
   }

  i = 0;
  while (!feof(arqin))
  {
      // Lê uma linha (com o '\n')
      result = fgets(linha, 100, arqin);  // lê até 99 caracteres ou até o '\n'
      if (result) {
	      printf("%s\n", linha);
          if ((i%100) == 0) 
              numbers = (double*)realloc(numbers, ((i/100)*100+100) * sizeof(double));
          numbers[i] = atof(linha);
          fprintf(arqout, "%d %.15lf\n", i, numbers[i]);  
      }
      i++;
  }

  for (int x=0; x < 5; x++)
       printf("double array: %.15lf\n", numbers[x]);

  fclose(arqout);
  fclose(arqin);
}