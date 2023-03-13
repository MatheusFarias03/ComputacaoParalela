#include <stdio.h>

int main(){
	int matriz[3][2];
	matriz[0][0] = 1;
	matriz[0][1] = 5;
	matriz[1][0] = 7;
	matriz[1][1] = 3;
	matriz[2][0] = 8;
	matriz[2][1] = 2;
	int matrizT[2][3];
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 3; j++){
			matrizT[i][j] = matriz[j][i];
		}
	}
	printf("Matriz Transposta: \n");
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 3; j++){
			printf("%d ", matrizT[i][j]);
		}
		printf("\n");
	}
	return 0;
}
