#include <stdio.h>
#define NLIN 2
#define NCOL 2

void multLinha(int matriz[NLIN][NCOL], int mult){
	for (int i = 0; i < NCOL; i++){
		matriz[0][i] = matriz[0][i] * mult;
	}
}

void multColuna(int matriz[NLIN][NCOL], int mult){
	for (int i = 0; i < NLIN; i++){
		matriz[i][0] = matriz[i][0] * mult;
	}
}

void print(int matriz[NLIN][NCOL]){
	for (int i = 0; i < NLIN; i++){
		for (int j = 0; j < NCOL; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int matriz[NLIN][NCOL] = {{7,3},{8,2}};
	int mult = 6;
	printf("Multiplicando a 1a linha:\n");
	multLinha(matriz, mult);
	print(matriz);
	printf("Multiplicando a 1a coluna:\n");
	multColuna(matriz, mult);
	print(matriz);
	return 0;
}
