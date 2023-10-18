#ifndef MERGESORT_H
#define MERGESORT_H

#include "quickSort.h"

// merge sort
template <typename r>
void merge(r arr[], int inicio, int meio, int fim){
    int tamanho = fim - inicio + 1;
    int fim1 = 0, fim2 = 0;
    int p1 = inicio, p2 = meio + 1;
    int i, j, k;

    auto temp = new r[tamanho];

    for (i = 0; i < tamanho; i++){
        if(!fim1 && !fim2){
            if(arr[p1] < arr[p2])
                temp[i] = arr[p1++];
            
            else 
                temp[i] = arr[p2++];
            
            if(p1 > meio)
                fim1 = 1;
            if(p2 > fim)
                fim2 = 1;
        }
        else{
            if(!fim1)
                temp[i] = arr[p1++];
            else
                temp[i] = arr[p2++];
        }
      
    }
    for(j = 0, k = inicio; j < tamanho; j++, k++){
        arr[k] = temp[j];
    }

    delete[] temp;
}

template <typename r>
void mergeSort(r arr[], int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim)/2;
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio+1, fim);
        merge(arr, inicio, meio, fim);
    }
}

#endif