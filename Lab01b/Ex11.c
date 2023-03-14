#include <stdio.h>
#define NLIN 2
#define NCOL 2

void soma(int matriz[NLIN][NCOL]){
	int somaL1 = 0;
	int somaL2 = 0;
	for (int i = 0; i < NLIN; i++){
		for (int j = 0; j < NCOL; j++){
			if (i == 0) somaL1 = somaL1 + matriz[i][j];
			else somaL2 = somaL2 + matriz[i][j];
		}
	}
	matriz[1][0] = somaL1;
	matriz[1][1] = somaL2;
}

void mult(int matriz[NLIN][NCOL]){
        int multL1 = 1;
	int multL2 = 1;
        for (int i = 0; i < NLIN; i++){
                for (int j = 0; j < NCOL; j++){
                        if (i == 0) multL1 = multL1 * matriz[i][j];
                        else multL2 = multL2 * matriz[i][j];
                }
        }
        matriz[1][0] = multL1;
        matriz[1][1] = multL2;
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
	int matriz[NLIN][NCOL] = {{3,11},{2,6}};
	printf("Somando as linhas:\n");
	soma(matriz);
	print(matriz);
	printf("\nMultiplicando as linhas:\n");
	mult(matriz);
	print(matriz);
	return 0;
}
