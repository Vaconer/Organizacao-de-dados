Deverá ser avaliado o desempenho do método de ordenação MergeSort (recursivo) considerando as seguintes entradas:

• Os elementos a serem ordenados são inteiros armazenados em um vetor de tamanho N.
• Os elementos a serem ordenados são inteiros armazenados em uma lista duplamente encadeada com N elementos.
• Os elementos a serem ordenados são registros armazenados em um vetor de tamanho N. 

Cada registro contém:
– Um inteiro, a chave para ordenação.
– Dez cadeias de caracteres (strings), cada uma como 200 caracteres.
– 1 booleano
– 4 números reais.

Para cada tipo de dado, você deverá implementar o Merge Sort Recursivo (como apresentado em sala de
aula) que recebe, como entrada, o conjunto de elementos a serem ordenados (uma Lista ou um vetor) e o
número de elementos a serem ordenados. Você deverá instrumentar os algoritmos para contabilizar o número de
comparações de chaves (linhas 7 e 8 do algoritmo apresentado em sala de aula) e o tempo total gasto na
ordenação. 
Estes números deverão ser impressos ao final de cada ordenação para posterior análise. Você ainda
deverá implementar funções para criação dos conjuntos de elementos aleatórios. Estas funções devem ser
chamadas uma vez para cada um dos N elementos a serem ordenados. Para o caso dos elementos serem
registros, a função de criação deve inicializar todos os campos do registro com valores aleatórios. Note que dois
elementos podem ter a mesma chave.

Análise:
O algoritmo Merge Sort deverá ser aplicado a entradas aleatórias com diferentes tamanhos (parâmetro N). 
Os valores de N deverão ser 1.000, 10.000, 100.000, 1.000.000, 10.000.000. 
Para cada valor de N você deverá gerar 5 (cinco) conjuntos de dados diferentes. 
O resultado de suas métricas será a média aritmética desses 5 valores.

O seu programa principal deve ser organizado da seguinte maneira:
• Recebe o valor de N e o arquivo de saída para os resultados. Estes parâmetros devem ser
passados pela linha de comando (argc e argv em C), como no exemplo:
quicksort 10000 saida10.txt

Resultados:
Apresente gráficos e/ou tabelas para as duas métricas pedidas, número de comparações e tempo de
execução (tempo de processamento), comparando o desempenho médio do Merge Sort para os três tipos de
estruturas de dados e diferentes valores de N. Discuta seus resultados.