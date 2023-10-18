#ifndef QUICKSORTMEDIANA_H
#define QUICKSORTMEDIANA_H

#include "QuicksortRecursivo.h"

// Função para encontrar a mediana de três valores
int findMedian(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    
    if (arr[low] > arr[mid])
        trocar(arr[low], arr[mid]);
    if (arr[low] > arr[high])
        trocar(arr[low], arr[high]);
    if (arr[mid] > arr[high])
        trocar(arr[mid], arr[high]);
    
    return arr[mid];
}

// Função para realizar a partição do array
int partition(int arr[], int low, int high, int &comparacoes) {
    int pivot = findMedian(arr, low, high);
    
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        comparacoes++; // Incrementa a contagem de comparações
        if (arr[j] <= pivot) {
            i++;
            trocar(arr[i], arr[j]);
        }
    }
    trocar(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortMedian(int arr[], int low, int high, int &comparacoes) {
    if (low < high) {
        int pi = partition(arr, low, high, comparacoes);

        // Recursivamente ordena os elementos antes e depois da partição
        quickSortMedian(arr, low, pi - 1, comparacoes);
        quickSortMedian(arr, pi + 1, high, comparacoes);
    }
}

#endif