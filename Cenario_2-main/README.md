Cenário 2: Variações do QuickSort

Você deverá comparar o desempenho de diferentes variações do Quicksort para ordenar um conjunto de N inteiros armazenados em um vetor. As variações do Quicksort a serem 
implementadas e avaliadas são:

  • Quicksort Recursivo: este é o Quicksort recursivo apresentado em sala de aula.
  
  • Quicksort Mediana(k): esta variaçãoo do Quicksort recursivo escolhe o pivô para partição como sendo a mediana de k elementos do vetor, aleatoriamente escolhidos. Experimente 
  com k = 3 e k = 5.
  
  • Quicksort Insercao(m): esta variação modifica o Quicksort Recursivo para utilizar o algoritmo de Inserção para ordenar partições (isto é, pedaços do vetor) com tamanho menor 
  ou igual a m. Experimente com m = 10 e m = 100.
  
  • Quicksort Iterativo: esta variação escolhe o pivô como o primeiro elemento (como apresentado em sala de aula), mas não é recursiva. Em outras palavras, esta é uma versão iterativa do Quicksort apresentado em sala de aula.
  
  Realize experimentos com as cinco variações considerando vetores aleatoriamente gerados com tamanho N = 1000, 5000, 10000, 50000, 100000, 500000 e 1000000, no mínimo. Estruture
o seu programa principal como sugerido acima para facilitar a coleta e posterior análise das estatísticas de desempenho.Apresente gráficos e/ou tabelas com os resultados obtidos. 
Discuta os resultados e conclusões obtidos. Qual variação tem melhor desempenho, considerando as diferentes métricas. Por quê? Qual o impacto das variações nos valores de k e de 
m nas versões Quicksort Mediana(k) e Quicksort Insercao(m)?
