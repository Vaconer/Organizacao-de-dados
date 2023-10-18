#include "quickSort.h"
#include "mergeSort.h"
#include "heapSort.h"
#include "alunoSort.h"
#include <ctime>

int *vetor;

void fill(int *arr, int size){
    int i;

    for (i = 0; i < size; i++){
        arr[i] = rand();
        // cout << arr[i] << " ";
    }
}

void print(int *arr, int size){
    int i;

    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

// (main.exe ou .\main.exe) (tamanho do vetor)
int main(int argv, char *argc[]){
    srand(time(0));

    if(argv != 2){
        cout<< "Erro: argv lower than expected (2)\n";
        return 0;
    }

    clock_t inicio, fim;
    unsigned long int tempo;

    int n = atoi(argc[1]);

    // --------------------------------------------------------
    vetor = (int *) malloc(n * sizeof(int));

    cout << "Elementos do vetor:";
    fill(vetor, n);

    inicio = clock();
    QuickSort(vetor, 0, n - 1);
    fim = clock();

    cout << "\n\nVetor ordenado pelo quick: ";
    print(vetor, n);

    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
    cout << "\n\nTempo de execucao do Quick Sort: " << tempo << " microssegundos\n";

    free(vetor);

    // --------------------------------------------------------
    vetor = (int *) malloc(n * sizeof(int));

    cout << "Elementos do vetor:";
    fill(vetor, n);

    inicio = clock();
    heapSort(vetor, n);
    fim = clock();
    
    cout << "\n\nVetor ordenado pelo Heap sort:"<<endl;
    print(vetor, n);
    
    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
    cout << "\n\nTempo de execucao do Heap Sort: " << tempo << " microssegundos" << endl;
    
    free(vetor);

    // --------------------------------------------------------
    vetor = (int *)malloc(n * sizeof(int));

    cout << "Elementos do vetor:";
    fill(vetor, n);

    inicio = clock();
    mergeSort(vetor, 0, n - 1);
    fim = clock();
    
    cout << "\n\nVetor ordenado pelo Merge: ";
    print(vetor, n);

    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
    cout << "\n\nTempo de execucao do Merge Sort: " << tempo << " microssegundos" << endl;

    free(vetor);

    // --------------------------------------------------------
    /*
    -O algoritmo escolhido foi o bubblesort, motivo? 
    -Porque é o mais fácil, porém muito mal otimizado.
    -Lide com isso

    ***********************************************************
    (!) Trocado para cocktail sort
        Motivo: nao pode ser um ja passado em aula
        Lide com isso
        (!) Se beber, nao dirija
    ***********************************************************
    */
    vetor = (int *)malloc(n * sizeof(int));

    cout << "Elementos do vetor:";
    fill(vetor, n);

    inicio = clock();
    CocktailSort(vetor, n);
    // (!) Beba com moderacao
    fim = clock();

    cout << "\n\nVetor ordenado pelo Aluno: ";
    print(vetor, n);

    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
    cout << "\n\nTempo de execucao do Aluno sort: "<< tempo <<" microssegundos"<<endl;

    free(vetor);
}