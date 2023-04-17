#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_SIZE 1000
/* Declaracao de variaveis globais. */

int m = MAX_SIZE; /* Linhas da matriz. */
int n = MAX_SIZE; /* Colunas da matriz. */
int A[MAX_SIZE][MAX_SIZE]; /* Matriz. */
int x[MAX_SIZE]; /* Vetor. */
int y[MAX_SIZE] = {0}; /* Array contendo resultado. */
int thread_count = 0; /* Numero de thread. */

/* Funcao para multiplicar elementos da matriz pelo vetor. */
void *Pth_mat_vect(void* rank)
{	
    long my_rank = (long) rank;
    int i, j;
    int local_m = m / thread_count;
    int my_first_row = my_rank * local_m;
    int my_last_row = (my_rank + 1) * local_m - 1;

    for (i = my_first_row; i <= my_last_row; i++)
    {
        for (j = 0; j < n; j++)
        {
            y[i] += A[i][j] * x[j];
        }
    }

    return NULL;
}

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

    /* Numero de threads que serao usados para a multiplicacao da matriz pelo vetor. */
    thread_count = strtol(argv[1], NULL, 10);

	/* Cria um array de threads. */
    pthread_t* thread_handles = malloc(thread_count * sizeof(pthread_t));

	/* Cria as threads. */
    for (long rank = 0; rank < thread_count; rank++)
    {
        pthread_create(&thread_handles[rank], NULL, Pth_mat_vect, (void*) rank);
    }

	/* Espera as threads terminarem. */
    for (long rank = 0; rank < thread_count; rank++)
    {
        pthread_join(thread_handles[rank], NULL);
    }

	/* Libera as threads. */
    free(thread_handles);

    return 0;
}
