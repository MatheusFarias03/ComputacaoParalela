Nesta primeira entrega do projeto (2/5/2023) conseguimos realizar a versão serial do número de euler, conseguindo alcançar por volta de 61 casas decimais

Tentando imprimir 65 casas decimais tivemos o seguinte resultado:

long double: 2.71828182845904523542816810799394033892895095050334930419921875000 

real    0m0.006s
user    0m0.006s
sys     0m0.000s

Screenshot:
![screenshot](https://raw.githubusercontent.com/MatheusFarias03/ComputacaoParalela/main/ProjetoTartaruga/Screenshot%20from%202023-05-02%2018-52-45.png)

Para a segunda entrega (9/5/2023) conseguimos realizar a versão paralela (inicial) do número de euler, porém encontramos certos problemas, conseguimos resultados positivos até o valor de n = 28, nesse caso todos os cálculos funcionaram perfeitamente, mas pudemos perceber que a partir de n = 29, o valor gerado pelo cálculo da somatrória de 1/x! sendo x iniciando em n/2 e indo até n, por razões desconhecidas até o momento, são gravados de forma incorreta na memória, como sera possível visualizar na imagem a seguir:

Screenshot:
![screenshot](https://github.com/MatheusFarias03/ComputacaoParalela/blob/main/ProjetoTartaruga/Screenshot%20from%202023-05-09.png)
