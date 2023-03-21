#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]){
        int fat = 23; // valor que desejamos calcular o fatorial
        int start, end; // valores para saber de onde cada processo comeca e ate onde vai
        int fd[2];
        if (pipe(fd) == -1){ // caso o pipe nao possa ser criado
                return 1;
        }

        int id = fork();
        if (id == -1){ // caso o fork nao possa ser criado
                return 1;
        }

        if (id == 0){ // processo filho vai de 1 ate o piso da metade do valor que desejamos obter o fatorial
                start = 1;
                end = fat / 2;
        } else { // processo pai vai do teto da metado do valor ate o valor em si
                start = fat / 2 + 1;
                end = fat;
        }

        int result = 1;
        int i;
        for (i = start; i <= end; i++){
                result = result * i;
        }

        printf("Calculo dos resultados parciais: %d\n", result); // mostra os valores obtidos em cada um dos processos

        if (id == 0){
                close(fd[0]);
                write(fd[1], &result, sizeof(result)); // grava o que foi obtido no processo pai na variavel result
                close(fd[1]);
        } else {
                int resultChild;
                close(fd[1]);
                read(fd[0], &resultChild, sizeof(resultChild)); // passa o que foi obtido no processo filho para a variavel resultChild
                close(fd[0]);

                int totalResult = result * resultChild; // gera o resultado final
                printf("Resultado final: %d\n", totalResult);
                wait(NULL);
        }

        return 0;
}
