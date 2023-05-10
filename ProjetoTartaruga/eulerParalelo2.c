#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <pthread.h>


/* Usado para evitar condicao de corrida. */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


/* Serve para guardar os dados passados para a thread. */
typedef struct thread_data {
        int factorial_num;
        int threads_num;
        int rank;
        mpf_t* total_result; 
} thread_data;


void euler_paralelo(void* arg)
{
        /* Adquirir os membros de arg. */
        thread_data* data = (thread_data*) arg;
        int factorial_num = data->factorial_num;
        int threads_num = data->threads_num;
        int rank = data->rank;
        mpf_t* total_result = data->total_result;

        /* Variaveis para cada thread. */
        int start, end;
        mpf_t child_result, result;

        start = (factorial_num / threads_num) * rank;
        end = (factorial_num / threads_num) * (rank + 1);

        mpf_init2(child_result, 33220);
        mpf_init2(result, 33220);
        mpf_set_ui(child_result, 0);
        mpf_set_ui(result, 1);

        /* Calcule uma soma local da fórmula no intervalo (start : end). */
        for (int i = 1; i <= end; i++)
        {
                if (i > start)
                {
                        mpf_div(result, result, i);
                        mpf_add(child_result, child_result, result);
                }
                else
                        mpf_div_ui(result, result, i);
        }

        /* Um bloqueio mutex é um mecanismo de sincronização que garante que 
        *  apenas um thread por vez possa acessar um recurso compartilhado ou 
        *  uma seção crítica do código. */
        pthread_mutex_lock(&mutex);

        mpf_add(total_result, total_result, child_result);

        pthread_mutex_unlock(&mutex);

        mpf_clear(child_result);
        mpf_clear(result);
}


int main(int argc, char* argv[])
{
        /* Erro se os argumentos estiverem errados. */
        if (argc != 2)
        {
                printf(stderr, "Usage: <threads_num> <factorial_num>");
                return 1;
        }


        /* Ler argumentos */
        int threads_num = strtol(argv[1], NULL, 10);
        int factorial_num = strtol(argv[2], NULL, 10);


        /* Inicializar a variabel do resultado com 33220 bits 
         * (equivalente a 10 mil casas decimais.) */
        mpf_t total_result;
        mpf_init2(total_result, 33220);
        mpf_set_ui(total_result, 1);


        /* Cria dinamicamente um array de threads e as threads em seguida. */
        pthread_t* array_threads = malloc(sizeof(pthread_t) * threads_num);
        for (int i = 0; i < threads_num; i++) 
        {
                thread_data data = { .factorial_num = factorial_num, .threads_num = threads_num, 
                                                        .rank = i, .total_result = &total_result };
                pthread_create(&array_threads[i], NULL, euler_paralelo, (void*) &data);
        }


        /* Espera as threads terminarem e entao libera as threads. */
        for (int i = 0; i < threads_num; i++)
                pthread_join(array_threads[i], NULL);    
        free(array_threads);


        gmp_printf("\nResultado final: %.10000Ff", total_result);
        printf("Done!");

        mpf_clear(total_result);

        return 0;
}
