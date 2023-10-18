#include "QuicksortMediana.h"
#include "QuickSortIterativo.h"
#include "QuicksortInsercao.h"
// #include <chrono>
// #include <cstdlib>
#include <ctime>

int *arr;

/*
    clock_t inicio, fim;
    unsigned long int tempo;

    inicio = clock();
    fim = clock();
    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
*/

void fill(int *arr, int tam){
    // cout << "Elementos do vetor:";
    for (int i = 0; i < tam; i++) {
        arr[i] = rand();
        // cout << arr[i] << " ";
    } 
}

void print(int *arr, int tam){
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
}

int main(int argv, char *argc[]){
    if(argv != 2){
        cout<< "Erro: Argv number different than expected (2)\n";
        return 0;
    }

    clock_t inicio, fim;
    unsigned long int tempo;
    int n = atoi(argc[1]), comp = 0;

    arr = (int *)malloc(n * sizeof(int));
    fill(arr, n);

    inicio = clock();

    QuickSort(arr, 0, n - 1, comp);

    fim = clock();
    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;

    // cout << "\nVetor ordenado pelo Recursivo: ";
    // print(arr, n);

    cout << "\n\nNumero de comparacoes no Quick Sort Recursivo: " << comp << "\n";
    cout << "Tempo de execucao do Quick Sort Recursivo: " << tempo << " microssegundos" << "\n";

    free(arr);

    // --------------------------------------------------------

    arr = (int *)malloc(n * sizeof(int));
    fill(arr, n);

    comp = 0;

    inicio = clock(); 

    quickSortMedian(arr, 0, n - 1, comp);

    fim = clock();
    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;

    // cout << "\nVetor ordenado pelo Mediana: ";
    // print(arr, n);

    cout << "\n\nNumero de comparacoes no Quick Sort Mediana: " << comp << "\n";
    cout << "Tempo de execucao do Quick Sort Mediana: " << tempo << " microssegundos" << "\n";

    free(arr);

    // --------------------------------------------------------

    arr = (int *)malloc(n * sizeof(int));
    fill(arr, n);

    comp = 0;
    inicio = clock();

    quickSortInsertion(arr, 0, n - 1, 5, comp);

    fim = clock();
    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;

    // cout << "\nVetor ordenado Insercao: ";
    // print(arr, n);

    cout << "\n\nNumero de comparacoes no Quick Sort Insercao: " << comp << "\n";
    cout << "Tempo de execucao do Quick Sort Insercao: " << tempo << " microssegundos" << "\n";

    free(arr);

    // --------------------------------------------------------

    arr = (int *)malloc(n * sizeof(int));
    fill(arr, n);

    comp = 0;

    inicio = clock();

    QuickSortIterativo(arr, 0, n - 1, comp);

    fim = clock();
    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;

    // cout << "\nVetor ordenado Iterativo: ";
    // print(arr, n);

    cout << "\n\nNumero de comparacoes no Quick Sort Iterativo: " << comp << "\n";
    cout << "Tempo de execucao do Quick Sort Iterativo: " << tempo << " microssegundos" << "\n"; 

    free(arr);

    return 0;
}
