#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_SIZE 1000
/* Declaracao de variaveis globais. */

int m = MAX_SIZE; /* Linhas da matriz */
int n = MAX_SIZE; /* Colunas da matriz. */
int A[MAX_SIZE][MAX_SIZE]; /* Matriz. */
int x[MAX_SIZE]; /* Vetor. */
int y[MAX_SIZE] = {0}; /* Array contendo resultado. */
int thread_count = 0; /* Numero de thread. */

int main(int argc, char* argv[])
{
	int contador_vetor = 1;
	int contador_matriz = 1;

	/* Preencher vetor e matriz. */
	for (int i = 0; i < MAX_SIZE; i++)
	{
		x[i] = contador_vetor;
		for (int j = 0; j < MAX_SIZE; j++)
		{
			A[i][j] = contador_matriz;
			contador_matriz++;
		}
		contador_vetor++;
		contador_matriz = 1;
	}

	for(int i=0; i<m; i++){
   		for(int j=0; j<n; j++){
      			y[i] += A[i][j] * x[j];
    		}
  	}
}
