#ifndef QUICKSORTITERATIVO_H
#define QUICKSORTITERATIVO_H

#include <stdio.h>
#include <stdlib.h>

// Função para trocar dois elementos de um array de inteiros
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para encontrar a posição correta do pivô no array
int Particionar(int array[], int inicio, int fim, int &comparacoes) {
    int pivo = array[inicio]; // Escolhe o primeiro elemento como pivô
    int i = inicio;

    for (int j = inicio + 1; j <= fim; j++) {
        comparacoes++; // Incrementa a contagem de comparações
        // Se o elemento atual for menor ou igual ao pivô
        if (array[j] <= pivo) {
            i++; // Incrementa o índice do elemento menor
            trocar(&array[i], &array[j]); // Troca o elemento atual com o elemento na posição i
        }
    }
    trocar(&array[i], &array[inicio]); // Coloca o pivô na posição correta
    return i; // Retorna o índice do pivô na posição correta
}

void QuickSortIterativo(int array[], int inicio, int fim, int &comparacoes) {
    int *pilhaInicio = (int *)malloc(sizeof(int) * (fim - inicio + 1));
    int *pilhaFim = (int *)malloc(sizeof(int) * (fim - inicio + 1));
    int topo = -1;

    pilhaInicio[++topo] = inicio;
    pilhaFim[topo] = fim;

    while (topo >= 0) {
        fim = pilhaFim[topo];
        inicio = pilhaInicio[topo--];

        int indicePivo = Particionar(array, inicio, fim, comparacoes);

        if (indicePivo - 1 > inicio) {
            pilhaInicio[++topo] = inicio;
            pilhaFim[topo] = indicePivo - 1;
        }

        if (indicePivo + 1 < fim) {
            pilhaInicio[++topo] = indicePivo + 1;
            pilhaFim[topo] = fim;
        }
    }

    free(pilhaInicio);
    free(pilhaFim);
}

#endif