#include <stdio.h>

typedef struct Pessoa{
	int idade;
	float peso;
	float altura;
	char* nome;
} Pessoa;

int main(){
	struct Pessoa Leonardo;
	struct Pessoa Matheus;
	struct Pessoa Carlos;
	Leonardo.idade = 19;
	Leonardo.peso = 50;
	Leonardo.altura = 1.60;
	Leonardo.nome = "Leonardo";
	Matheus.idade = 22;
	Matheus.altura = 1.80;
	Matheus.peso = 120;
	Matheus.nome = "Matheus";
	Carlos.idade = 25;
	Carlos.altura = 1.15;
	Carlos.peso = 200;
	Carlos.nome = "Carlos";
	struct Pessoa vetor[3] = {Leonardo, Matheus, Carlos};
	for (int i = 0; i < 3; i++){
		printf("%s:\n", vetor[i].nome);
		printf("Idade: %d\n", vetor[i].idade);
		printf("Peso: %.2f\n", vetor[i].peso);
		printf("Altura: %.2f\n", vetor[i].altura);
	}
	return 0;
}
