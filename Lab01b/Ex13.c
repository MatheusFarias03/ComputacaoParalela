#include <stdio.h>

void removeChar(char* array, int pos, int str_len)
{
	char* copiedStr = array;
	for (int i = 0; i < str_len; i++)
	{
		if (i == pos)
			array[pos] = ' ';
		else
			array[i] = copiedStr[i];
	}
}

int main()
{
	char Str[100];
	char Vogais[5] = {'a', 'e', 'i', 'o', 'u'};
	int i;
	int removePos = 37;

	// Inserir varios caracteres.
	for (i = 0; i < 100; i++)
	{
		Str[i] = Vogais[i % 5]; // Inserir uma vogal de acordo com o "i"
	}

	printf("\nA string antes: \n%s\n", Str);

	removeChar(Str, removePos, 100);

	printf("\nA string depois: \n%s\n", Str);	

	return 0;
}
