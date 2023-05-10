1) Resumindo são duas tarefas principais, a primeira (S1) irá fazer o somatorio de 1/x! sendo que x começará em 1 e irá até n/2, sendo o n o maior valor do somatório, enquanto a segunda tarefa (S2) irá também fazer um somatório porém começando com x em n/2 + 1 e indo até n propriamente dito.

Screenshot: ![screenshot](https://github.com/MatheusFarias03/ComputacaoParalela/blob/main/ProjetoTartaruga/DecomposicaoTarefas/DAG.png) 

2) Com base no DAG a cima e na resposta da questão anterior, concluímos que a tarefa que irá tomar mais tempo será a segunda, que pode ser vista como S2, visto que está necessitará de mais tempo já que irá calcular valores maiores para os fatoriais de x. Então, o limite inferior do tempo de execução paralela é o tempo necessário para executar o somatório em S2.

3) Considerando que cada tarefa irá sempre precisar de uma unidade de tempo, podemos perceber que independente do número de tarefas executando em paralelo, o tempo gasto total pelo programa será sempre o mesmo, nunca superando o serial que seria uma única unidade de tempo para sua única tarefa em execução.

4) No cenário do projeto apenas duas tarefas serão realizadas ao mesmo tempo, em paralelo, de acordo com a imagem disponibilizada após a resposta da primeira questão, seriam S1 e S2.

5) O paralelismo médio poderia ser calculado ao dividirmoso número de tarefas realizadas pelo tempo total gasto para a execução, sendo assim, ao considerarmos que todas as tarefas consomem uma unidade de tempo para execução e que elas são realizadas simultanemante, teríamos 1 para o tempo total, a conta então ficaria  2/1 que resultaria em 2.
