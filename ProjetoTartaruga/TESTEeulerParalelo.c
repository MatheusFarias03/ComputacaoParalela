#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <pthread.h>
#include <unistd.h>
#include <omp.h>

void euler_paralelo(int factorial_num, int threads_num, int rank, mpf_t* total_result)
{
        /* Variaveis para cada thread. */
        int start, end;
        mpf_t fat, div, euler, cur_res;

        start = (factorial_num / threads_num) * rank;
        end = (factorial_num / threads_num) * (rank + 1);

        mpf_init2(euler, 33220);
        mpf_init2(div, 33220);
        mpf_init2(fat, 33220);
        mpf_init2(cur_res, 33220);
        mpf_set_ui(euler, 0);
        mpf_set_ui(div, 1);
        mpf_set_ui(fat, 1);
        // mpf_set_ui(cur_res, 1);
	int i;

        /* Calcule uma soma local da fórmula no intervalo (start : end). */
	if (start == 0) start = 1;

        for (i = start; i <= end; i++){
   		mpf_mul_ui(fat, fat, i);
    		mpf_ui_div(div, 1, fat);
    		mpf_add(euler, euler, div);
  	}

        /* Um bloqueio mutex é um mecanismo de sincronização que garante que 
        *  apenas um thread por vez possa acessar um recurso compartilhado ou 
        *  uma seção crítica do código. */
        #pragma omp critical

        mpf_add(*total_result, *total_result, euler);
        gmp_printf("\nResultado parcial: %.15Ff", euler);

        mpf_clear(div);
        mpf_clear(fat);
}


int main(int argc, char* argv[])
{
        /* Erro se os argumentos estiverem errados. */
        if (argc != 3)
        {
                printf("Usage: <threads_num> <factorial_num>");
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

	
        /* Permite paralelismo no programa. */
        #pragma omp parallel num_threads(threads_num)
	
	// int rank = omp_get_thread_num();
	euler_paralelo(factorial_num, threads_num, omp_get_thread_num(), &total_result);
        gmp_printf("\nResultado final: %.10000Ff", total_result);
        mpf_clear(total_result);

        return 0;
}


