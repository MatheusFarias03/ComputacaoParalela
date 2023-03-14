#include <stdio.h>

int posChar(char* word, char find, int str_len)
{
	int pos = 0; // Guarda a posicao do caracter
	
	for (pos; pos < str_len; pos++)
	{
		if(word[pos] == find)
			return pos+1;
	}
	return -1;
}

int main()
{
	char* myString = "Abacate";
	int position = posChar(myString, 't', 7);
	printf("\nA posicao da palavra %s eh %d.\n", myString, position);

	return 0;
}
