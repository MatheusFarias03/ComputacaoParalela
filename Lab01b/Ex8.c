#include <stdio.h>
#include <stdlib.h>

int** transposta(int** matriz, int linhas, int colunas){
	int** m = (int**)malloc(sizeof(int*)*linhas);
	for (int i = 0; i < linhas; i++){
		m[i] = (int*)malloc(sizeof(int)*colunas);
	}
       	for (int i = 0; i < colunas; i++){
		for (int j = 0; j < linhas; j++){
			m[i][j] = matriz[j][i];
		}
	}
	return m;
}

int main(){
	int** matriz (int**)malloc(sizeof(int*)*3);
	for (int i = 0; i < 3; i++){
		matriz[i] = (int*)malloc(sizeof(int)*2);
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 2; j++){
			matriz[i][j] = i * j;
		}
	}
	int** matrizT = transposta(matriz, 3, 2);
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 3; j++){
			printf("%d ", matrizT[i][j]);
		}
		printf("\n");
	};
	return 0;
}
