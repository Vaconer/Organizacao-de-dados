#include "QuicksortRecursivo.h"

//Função de partição para o Quick Sort
int partition1(int arr[], int low, int high, int &comparacoes) {
    int pivot = arr[high]; // Escolhe o último elemento como pivô
    int i = (low - 1);    // O índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        comparacoes++; // Incrementa a contagem de comparações
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento
            std::swap(arr[i], arr[j]);
        }
    }
    trocar(arr[i + 1], arr[high]);
    return (i + 1);
}

// Função de inserção simples
void insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função Quick Sort com inserção
void quickSortInsertion(int arr[], int low, int high, int insertionThreshold, int &comparacoes) {
    if (low < high) {
        // Verifica se o tamanho da partição é menor que o limiar de inserção
        if (high - low + 1 <= insertionThreshold) {
            insertionSort(arr, low, high);
        } else {
            int pi = partition1(arr, low, high, comparacoes);

            // Recursivamente ordena os elementos antes e depois da partição
            quickSortInsertion(arr, low, pi - 1, insertionThreshold, comparacoes);
            quickSortInsertion(arr, pi + 1, high, insertionThreshold, comparacoes);
        }
    }
}