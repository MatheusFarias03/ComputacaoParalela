#include <stdio.h>

int main(){
	char* nome1 = "Joana";
	char* nome2 = "Banana";
	char* primeiro;
	char* segundo;
	for (int i = 0; i < 5; i++){
		if (nome1[i] > nome2[i]){
			primeiro = nome2;
			segundo = nome1;
			break;
		}
		else {
			primeiro = nome1;
			segundo = nome2;
			break;
		}
	}
	printf("%s\n", primeiro);
	printf("%s", segundo);
	return 0;
}
