#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char* argv[]){
	
	// Checagem de quantidade de argumentos passados.
	if (argc < 2)
	{
		printf("Usage: pass the number to calculate the sum of 1/factorial of it.\n");
		return 1;
	}

  int value = atoi(argv[1]); // Valor, passado como argumento, que desejamos calcular o fatorial.
  int start, end; // Valores para saber de onde cada processo comeca e ate onde vai.
  int fd[2]; // File Descriptors. Inteiros que representam um arquivo aberto.
  
  mpf_t euler, eulerChild, fat, totalResult;
  mpf_init2(euler, 3350000U);
  mpf_init2(fat, 3350000U);
  mpf_init2(totalResult, 3350000U);
  mpf_set_ui(totalResult, 1);
        
	// Caso o pipe nao possa ser criado.
	if (pipe(fd) == -1)
    return 1;

	// Criar um novo processo.
  int id = fork();

	// Caso o novo processo nao possa ser criado.
  if (id == -1) 
    return 1;

	// Processo filho vai de 1 ate o piso da metade do valor que desejamos obter o fatorial.
  if (id == 0) { 
    start = 1;
    end = value / 2;
    // printf("Id 0 -> Start: %d, End: %d\n\n", start, end);
  } 
	
	// Processo pai vai do teto da metado do valor ate o valor em si.
  else { 
    start = value / 2 + 1;
    end = value;
    // printf("Id X -> Start: %d, End: %d\n\n", start, end);
  }
  
  mpf_set_ui(fat, 1);
  mpf_t div;
  mpf_init2(div, 1);
  mpf_set_ui(div, 1);
  int i;
  
  for (i = start; i <= end; i++){
    mpf_mul_ui(fat, fat, i);
    mpf_ui_div(div, 1, fat);
    mpf_add(euler, euler, div);
  }

  gmp_printf("Calculo dos resultados parciais: %.100Ff\n", euler);
  // printf("\nCalculo dos resultados parciais: %Lf\n", euler); 

  if (id == 0){
    close(fd[0]);
    write(fd[1], &euler, sizeof(euler)); // grava o que foi obtido no processo pai na variavel result
    close(fd[1]);
  } 
	
  else {
    close(fd[1]);
    read(fd[0], &eulerChild, sizeof(euler)); // passa o que foi obtido no processo filho para a variavel resultChild
    close(fd[0]);
    
    mpf_add(totalResult, totalResult, euler);
    gmp_printf("Total Result + euler: %.15Ff\n", totalResult);

    gmp_printf("Euler Child: %.15Ff\n", eulerChild);
   
    // gmp_printf("Resultado Final: %.9999Ff\n", totalResult);
  
    mpf_clear(totalResult);
    wait(NULL);
  }
  mpf_clear(euler);
  mpf_clear(div);
  mpf_clear(fat);
  return 0;
}
