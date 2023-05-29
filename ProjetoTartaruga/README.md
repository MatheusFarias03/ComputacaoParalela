Nesta primeira entrega do projeto (2/5/2023) conseguimos realizar a versão serial do número de euler, conseguindo alcançar por volta de 61 casas decimais

Tentando imprimir 65 casas decimais tivemos o seguinte resultado:

long double: 2.71828182845904523542816810799394033892895095050334930419921875000 

real    0m0.006s
user    0m0.006s
sys     0m0.000s

Screenshot:
![screenshot](https://raw.githubusercontent.com/MatheusFarias03/ComputacaoParalela/main/ProjetoTartaruga/Screenshot%20from%202023-05-02%2018-52-45.png)

Para a segunda entrega (9/5/2023) conseguimos realizar a versão paralela (inicial) do número de euler, porém encontramos certos problemas, conseguimos resultados positivos até o valor de n = 28, nesse caso todos os cálculos funcionaram perfeitamente, mas pudemos perceber que a partir de n = 29, o valor gerado pelo cálculo da somatrória de 1/x! sendo x iniciando em n/2 e indo até n, por razões desconhecidas até o momento, são gravados de forma incorreta na memória, como pode ser visto na imagem a seguir:

Screenshot:
![screenshot](https://github.com/MatheusFarias03/ComputacaoParalela/blob/main/ProjetoTartaruga/Screenshot%20from%202023-05-09.png)

Após a última entrega, desenvolvemos um novo código (TESTEeulerParalelo.c) que desta vez funcional, imprimindo corretamente 10000 casas e realizando em paralelo, acreditamos que o problema da última entrega era a condição de corrida, onde não estávamos usando semáforos para realizar as trocas de valores. 
As imagens a seguir mostram o resultado que conseguimos e os tempos de execução.

Os resultados parciais são os cálculos da somatória de 1/x!, com o primeiro valor indo de x = 1 até x = 5000, e o segundo indo de x = 5001 até x = 10000. Em nosso código a variável que recebe o resultado final ja começa em 1 considerando o 1/0!.

Resultado (na imagem não é possível ver todos os números decimais gerados):
![screenshot](https://github.com/MatheusFarias03/ComputacaoParalela/blob/main/ProjetoTartaruga/Screenshot_Resultado_Euler.png)

Tempo de Execução:

![screenshot](https://github.com/MatheusFarias03/ComputacaoParalela/blob/main/ProjetoTartaruga/Screenshot_Tempo_Euler.png)

Projeto Final:

Com o projeto finalizado, iremos responder os seguintes pontos:
* Como resolveram o problema:  descrição simples do algoritmo e estratégia de paralelismo adotada

  Nosso código recebe duas entradas, número de threads que serão utilizadas e o valor de n (valor máximo do fatorial calculado a cada divisão realizada pela série de Taylor), então dividimos o código de acordo com a quantidade de threads, cada thread irá realizar uma parte do somatório.
  
  Dentro da função euler_paralelo (função que realiza do somatório), são inicializadas várias variáveis para cada thread, incluindo start e end para determinar a faixa de cálculo de cada thread, fat para o fatorial parcial, div para o resultado da divisão, euler para armazenar a soma parcial e cur_res para resultados intermediários. 
  
  Para a realização do projeto utilizamos duas principais bibliotecas (OMP - Open Multi-Processing e GMP - GNU Multiple-Precision), a biblioteca OMP foi utilizada para garantir o paralelismo, escolhemos utilizar essa biblioteca pela facilidade para lidar com os problemas de corrida, a diretiva #pragma omp critical auxiliou gerando uma área crítica, que, no nosso caso, impede que uma thread modifique o valor de uma variável enquanto outra tenta o mesmo. Já a biblioteca GMP foi utilizada para que fosse possível armazenar e realizar cálculos com números com diversas casas decimais, por exemplo, as variáveis mencionadas anteriormente (fat, euler e cur_res) foram inicializadas utilizando o tipo mpf_t, para que fossem variáveis de tamanho maior que double e com maior precisão.
  
* Qual foi o speedup da última versão e como eles fizeram para melhorar

  Ao longo do desenvolvimento do projeto não nos focamos em melhorar o código serial para além do que foi entregue, nesse código, ao tentar executar para um tamanho n de 10000 conseguimos o tempo real de 0m4.223s, já para o paralelo, como visto nos prints das últimas entregas conseguimos chegar em um tempo de 0m1.470s para o mesmo valor de n, o que nos daria um speedup de aproximadamente 2.873. No melhor dos cenários o que deveria ser feito para melhorar o speedup seria diminuir o tempo de ambos os códigos, porém como dito anteriormente nosso grupo se concentrou em diminuir o máximo que conseguíssemos o tempo do código paralelo, o que já foi suficiente para que ao decorrer das entregas percebessemos um aumento no valor do speedup.
  
* Considerações sobre a estratégia de paralelismo adotada e como isso auxiliou na escala do problema. 

  O intervalo de cálculo é determinado com base no factorial_num e threads_num, dividindo o trabalho igualmente entre as threads. As variáveis são inicializadas e definidas com valores iniciais apropriados. Um loop é executado para calcular a soma parcial da fórmula de Euler no intervalo determinado para a thread atual. O fatorial parcial é atualizado a cada iteração e a divisão do fatorial pelo fatorial parcial é adicionada à soma parcial. Uma região crítica é definida usando #pragma omp critical, garantindo que apenas uma thread por vez possa acessar o recurso compartilhado total_result. A soma parcial é adicionada ao total_result usando a função mpf_add da biblioteca GMP.
  
  Como pode ser visto ao longo das entregas, o maior problema que nosso grupo enfrentou foi a respeito da condição de corrida, em uma das primeiras versões do nosso código ainda não estávamos usando OMP, ao invés dessa biblioteca estávamos usando pthread, juntamente com Mutex, o que limitou o potencial do nosso código visto que não estávamos tratando da condição de corrida, ou seja, os cálculos eram feitos corretamente porém uma thread ignorava a outra e sobrescrevia os valores em uma variável. Como mencionado anteriormente, quando passamos a utilizar OMP com #pragma omp critical conseguimos fazer com que nosso código não tivessse mais limitações a respeito das variáveis, independente do valor de n que dosse passado para a função, as threads não sobrescreviam umas as outras, trazendo uma maior confiabilidade ao código.
