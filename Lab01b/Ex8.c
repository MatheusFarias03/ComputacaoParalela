#include <stdio.h>
#define NLIN 3
#define NCOL 2

void transposta(int matriz[NLIN][NCOL], int matrizT[NCOL][NLIN]){
	for (int i = 0; i < NCOL; i++){
		for (int j = 0; j < NLIN; j++){
			matrizT[i][j] = matriz[j][i];
		}
	}
}

int main(){
	int matriz[NLIN][NCOL] = {{1,5},{7,3},{8,2}};
	int matrizT[NCOL][NLIN];
	transposta(matriz, matrizT);
	for (int i = 0; i < NCOL; i++){
		for (int j = 0; j < NLIN; j++){
			printf("%d ", matrizT[i][j]);
		}
		printf("\n");
	};
	return 0;
}
