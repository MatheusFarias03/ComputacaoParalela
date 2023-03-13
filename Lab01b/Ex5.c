#include <stdio.h>

int main(){
	int matriz[2][2];
	matriz [0][0] = 2;
	matriz [0][1] = 5;
	matriz [1][0] = 3;
	matriz [1][1] = 7;
	int mult = 7;
	printf("Multiplicando a 1a linha: \n");
	printf("[%d,%d],[%d,%d]\n", matriz[0][0] * mult, matriz[0][1] * mult, matriz[1][0], matriz[1][1]);
	printf("Multiplicando a 1a coluna: \n");
	printf("[%d,%d],[%d,%d]\n", matriz[0][0] *mult, matriz[0][1], matriz[1][0] * mult, matriz[1][1]);
	return 0;
}
