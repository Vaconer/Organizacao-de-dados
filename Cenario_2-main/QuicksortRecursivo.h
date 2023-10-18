#ifndef QUICKSORTRECURSIVO_H
#define QUICKSORTRECURSIVO_H

#include <iostream>
// #include <vector>

using namespace std;

// Função para trocar dois elementos de um vetor
void trocar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Função para encontrar a posição correta do pivo no vetor
int particionar(int vetor[], int inicio, int fim, int &comparacoes) {
    int pivo = vetor[fim]; // Escolhe o elemento mais à direita como pivo
    int i = (inicio - 1); // Inicializa o índice do menor elemento

    for (int j = inicio; j <= fim - 1; j++) {
        comparacoes++; // Incrementa a contagem de comparações
        // Se o elemento atual for menor ou igual ao pivo
        if (vetor[j] <= pivo) {
            i++; // Incrementa o índice do menor elemento
            trocar(vetor[i], vetor[j]);
        }
    }
    trocar(vetor[i + 1], vetor[fim]);
    return (i + 1);
}

void QuickSort(int vetor[], int inicio, int fim, int &comparacoes) {
    if (inicio < fim) {
        // Encontra a posição correta do pivo e coloca o pivo na posição correta
        int indice_pivo = particionar(vetor, inicio, fim, comparacoes);

        // Recursivamente ordena os elementos antes e depois da posição do pivo
        QuickSort(vetor, inicio, indice_pivo - 1, comparacoes);
        QuickSort(vetor, indice_pivo + 1, fim, comparacoes);
    }
}


#endif