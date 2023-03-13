#include <stdio.h>

int main(){
	int inicio = 1;
	int fim = 10;
	for (int i = 0; i < 5; i++){
		for (int j = inicio; j < fim; j++){
			printf("%d ", j);
		}
		printf("\n");
		for (int s = 1; s <= inicio; s++){
			printf(" ");
		}
		inicio++;
		fim--;
	}
	return 0;
}
