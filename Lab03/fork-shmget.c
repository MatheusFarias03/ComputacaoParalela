#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ADDKEY 123

// OBS: SHM_R=0400 SHM_W=200 SHM_R AND SHM_W = 0600

int main() {
        int shmid ; /* identificador da memória comum */
        int size = 1024 ;
	char *path="./" ;
        pid_t childPID;
	if (( shmid = shmget(ftok(path,ADDKEY), size, IPC_CREAT|IPC_EXCL|SHM_R|SHM_W)) == -1) {
                perror("Erro no shmget") ;
                exit(1) ;
        }
	int* ptr = shmat(shmid, (void*) 0, 0);
	*ptr = 1;
	printf("Valor (Inicial): %d \n", *ptr);
	childPID = fork();
	if (childPID == -1){
		perror("Erro no fork");
		return 1;
	}
	else if (childPID == 0){
		*ptr += 2;
		printf("Valor (apos soma no processo filho): %d \n", *ptr);
	}
	else {
		wait(NULL);
		*ptr *= 4;
		printf("Valor (apos multiplicacao no processo pai): %d \n", *ptr);
		if ((shmctl(shmid, IPC_RMID, NULL)) == -1){
			perror("Erro no shmctl()");
			exit(1);
		}
		exit(0);
	}
}
