#ifndef MERGE_H
#define MERGE_H

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
using namespace std;
#endif

#include "dataTypes.h"

// merge sort
template <typename r>
void merge(r arr[], int inicio, int meio, int fim, int &com){
    int tamanho = fim - inicio + 1;
    int fim1 = 0, fim2 = 0;
    int p1 = inicio, p2 = meio + 1;
    int i, j, k;

    auto temp = new r[tamanho];

    for (i = 0; i < tamanho; i++){
        if(!fim1 && !fim2){
            com++; // contador de comparacao
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
void mergeSort(r arr[], int inicio, int fim, int &com){
    if(inicio < fim){
        int meio = (inicio + fim)/2;
        mergeSort(arr, inicio, meio, com);
        mergeSort(arr, meio+1, fim, com);
        merge(arr, inicio, meio, fim, com);
    }
}

// ------------------------------------------------------------
bool compareReg(Registro r1, Registro r2){
    if(r1.chave < r2.chave)
        return true;
    return false;
}

void mergeReg(Registro arr[], int inicio, int meio, int fim, int &com){
    int tamanho = fim - inicio + 1;
    int fim1 = 0, fim2 = 0;
    int p1 = inicio, p2 = meio + 1;
    int i, j, k;

    auto temp = new Registro[tamanho];

    for (i = 0; i < tamanho; i++){
        if(!fim1 && !fim2){
            com++; // contador de comparacao
            // if(arr[p1].chave < arr[p2].chave)
            if(compareReg(arr[p1], arr[p2]))
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
        // cout<<"test1";

    }
    for(j = 0, k = inicio; j < tamanho; j++, k++){
        arr[k] = temp[j];
        // cout<<"Finished";
    }
    delete[] temp;
}

void mergeSortReg(Registro arr[], int inicio, int fim, int &com){
    if(inicio < fim){
        int meio = (inicio + fim)/2;
        mergeSortReg(arr, inicio, meio, com);
        mergeSortReg(arr, meio+1, fim, com);
        mergeReg(arr, inicio, meio, fim, com);
    }
}

// ------------------------------------------------------------
void mergeList(List l, int inicio, int meio, int fim, int &com){
    int tamanho = fim - inicio + 1;
    int fim1 = 0, fim2 = 0;
    int p1 = inicio, p2 = meio + 1;
    int i, j, k;

    Node *aux, *aux2;
    List temp;

    start(temp);

    for(i = 0; i <tamanho; i++){
        aux = index(l, p1);
        aux2 = index(l, p2);

        if(!fim1 && !fim2){
            com++;
            if(aux->data < aux2->data){
                copy(temp, aux);
                p1++;
            } 
            else {
                copy(temp, aux2);
                p2++;
            }

            if(p1 > meio)
                fim1 = 1;
            if(p2 > fim)
                fim2 = 1;
        }
        else{
            if(!fim1){
                copy(temp, aux);
                p1++;
            }
            else {
                copy(temp, aux2);
                p2++;
            }
        }
    }

    cout<<"\nTemp:\n";
    watch(temp);

    for(j = 0, k = inicio; j < tamanho; j++, k++){
        swapItem(l, temp, k, j);
        // cout<<"Finished";
    }

    cout<<"\nTemp 2:\n";
    watch(temp);

    cout<<"\nList:\n";
    watch(l);

    restart(temp);
    delete aux;
    delete aux2;
}

void mergeSortList(List l, int inicio, int fim, int &com){
    if(inicio < fim){
        int meio = (inicio + fim)/2;
        mergeSortList(l, inicio, meio, com);
        mergeSortList(l, meio+1, fim, com);
        mergeList(l, inicio, meio, fim, com);
    }
}

// ------------------------------------------------------------
Node* split(Node* aux){ 
	Node *fast = aux,*slow = aux;

	while(fast->next && fast->next->next){ 
		fast = fast->next->next; 
		slow = slow->next; 
	}

	Node* temp = slow->next;
	slow->next = NULL;
	return temp;
}

Node *merge(Node *first, Node *second, int &comp){
    comp++;
	// If first linked list is empty 
	if(!first){
        // delete first;
		return second; 
    }

	// If second linked list is empty 
	if (!second){
        // delete second;
		return first;
    }

	// Pick the smaller value 
	if (first->data < second->data){ 
		first->next = merge(first->next,second, comp); 
		first->next->prev = first; 
		first->prev = NULL;
        // delete second;
		return first; 
	} 
	else{ 
		second->next = merge(first,second->next, comp); 
		second->next->prev = second; 
		second->prev = NULL; 
        // delete first;
		return second; 
	} 
} 

// Function to do merge sort 
Node* mergeSort(Node* first, int &comp){ 
    if( !first || !first->next)
        return first;

    Node* second = split(first);
    
    first = mergeSort(first, comp);
    second = mergeSort(second, comp);

    return merge(first, second, comp);
}

#endif