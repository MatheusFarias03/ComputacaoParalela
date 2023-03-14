#include <stdio.h>
#define NLIN 2
#define NCOL 2

void modulo(int matriz[NLIN][NCOL]){
	for (int i = 0; i < NLIN; i++){
		for (int j = 0; j < NCOL; j++){
			if (matriz[i][j] < 0) matriz[i][j] = matriz[i][j] * (-1);
		}
	}
}

int main(){
	int matriz[NLIN][NCOL] = {{-2,5},{3,-8}};
	modulo(matriz);
	for (int i =0; i < 2; i++){
		for (int j = 0; j < 2; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	return 0;
}
