#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]){
	int fat = 23;
	int start, end;
	int fd[2];
	if (pipe(fd) == -1){
		return 1;
	}

	int id = fork();
	if (id == -1){
		return 1;
	}
	
	if (id == 0){
		start = 1;
		end = fat / 2;
	} else {
		start = fat / 2 + 1;
		end = fat;
	}

	int result = 1;
	int i;
	for (i = start; i <= end; i++){
		result = result * i;
	}

	printf("Calculo dos resultados parciais: %d\n", result);

	if (id == 0){
		close(fd[0]);
		write(fd[1], &result, sizeof(result));
		close(fd[1]);
	} else {
		int resultChild;
		close(fd[1]);
		read(fd[0], &resultChild, sizeof(resultChild));
		close(fd[0]);

		int totalResult = result * resultChild;
		printf("Resultado final: %d\n", totalResult);
		wait(NULL);
	}

	return 0;
}
