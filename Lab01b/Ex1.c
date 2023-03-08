#include <stdio.h>

int Ex1(){
	int matriz[2][2];
	matriz[0][0] = 37;
	matriz[0][1] = 24;
	matriz[1][0] = 12;
	matriz[1][1] = 73;
	int menor = matriz[0][0];
	int menorLinha = 0;
	for (int i = 1; i < 2; i++){
		for (int j = 0; i < 2; i++){
			if (matriz[i][j] < menor){
				menor = matriz[i][j];
				menorLinha = i;
			}	
		}
	}
	return menorLinha;
}

int  main(){
	int linha = Ex1();
	printf("%d", linha);
	return 0;
}
