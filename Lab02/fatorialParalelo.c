#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]){
	
	// Checagem de quantidade de argumentos passados.
	if (argc < 2)
	{
		printf("Usage: pass the number to calculate the factorial of it.\n");
		return 1;
	}

        int value = atoi(argv[1]); // Valor, passado como argumento, que desejamos calcular o fatorial.
        int start, end; // Valores para saber de onde cada processo comeca e ate onde vai.
        int fd[2]; // File Descriptors. Inteiros que representam um arquivo aberto.
        
	// Caso o pipe nao possa ser criado.
	if (pipe(fd) == -1)
                return 1;

	// Criar um novo processo.
        int id = fork();

	// Caso o novo processo nao possa ser criado.
        if (id == -1) 
                return 1;

	// Processo filho vai de 1 ate o piso da metade do valor que desejamos obter o fatorial.
        if (id == 0)
	{ 
                start = 1;
                end = value / 2;
        } 
	
	// Processo pai vai do teto da metado do valor ate o valor em si.
	else 
	{ 
                start = value / 2 + 1;
                end = value;
        }

        long long int fat = 1;
        int i;
        
	for (i = start; i <= end; i++)
                fat = fat * i;

        printf("Calculo dos resultados parciais: %lld\n", fat); 

        if (id == 0)
	{
                close(fd[0]);
                write(fd[1], &fat, sizeof(fat)); // grava o que foi obtido no processo pai na variavel result
                close(fd[1]);
        } 
	
	else {
                long long int fatChild;
                close(fd[1]);
                read(fd[0], &fatChild, sizeof(fatChild)); // passa o que foi obtido no processo filho para a variavel resultChild
                close(fd[0]);

                long long int totalResult = fat * fatChild; // gera o resultado final
                printf("Resultado final: %lld\n", totalResult);
                wait(NULL);
        }

        return 0;
}
