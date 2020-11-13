#include <stdio.h>
#include <stdlib.h> //necessário para usar as funções malloc() e free()
#include <curses.h>

void liberarMatriz(int **p, int N)
{
  for (int i = 0; i < N; i++)
  {
    free(p[i]);
  }
  free(p);
}

int main()
{
  int **p = NULL; //definindo o ponteiro p
  int i, dim, j;

  printf("Informe o numero de dimensao da matriz\n");
  scanf("%d", &dim);

  p = (int **)malloc(dim * sizeof(int *));
  //printf("%d", **p); //por desencargo print

  for (i = 0; i < dim; i++)
  {
    p[i] = (int *)malloc(dim * sizeof(int)); //criando o vetor para o ponteiro i
    for (j = 0; j < dim; j++)
    {
      scanf("%d", &p[i][j]);
    }
  }

  liberarMatriz(p, dim);

  return 0;
}