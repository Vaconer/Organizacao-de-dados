#ifndef DATATYPES_H
#define DATATYPES_H

#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

struct Registro {
    int chave;
    char nomes [10][200];
    bool flag;
    float arr[4];
};

#include "./DoubleLinkedList.h"

// ------------------------------------------------------------
// Randomness generator area
template <typename r>
void fillArray(r arr[], int tam){
    int i;
    int lowerLimit = 1, upperLimit = tam;
    for(i=0; i<tam; i++)
        arr[i] = (rand() % (upperLimit - lowerLimit + 1)) + lowerLimit;
}

template <typename r>
void fillArray(r arr[], int tam, int lowerLimit, int upperLimit){
    int i;
    for(i=0; i<tam; i++)
        arr[i] = (rand() % (upperLimit - lowerLimit + 1)) + lowerLimit;
}

void fillRegistry(Registro array[], int tam){
    int i, j;
    int lowerLimit = 1, upperLimit = tam;
    for(i=0; i<tam; i++){
        array[i].chave = rand();
        array[i].flag  = (rand() % (1 - 0 + 1)) + 0;

        // missing char nome
        for(j=0; j<10; j++)
            fillArray(array[i].nomes[j], 20, 65, 90);
        
        for(j=0; j<4; j++)
            // fillArray(array[i].arr[j], 4, 0, 100);
            array[i].arr[j] = (rand() % (upperLimit - lowerLimit + 1)) + lowerLimit;
    }
}

void fillList(List &list, int tam){
    int i, aux;
    int lowerLimit = 1, upperLimit = tam;
    for(i=0; i<tam; i++){
        aux = (rand() % (upperLimit - lowerLimit + 1)) + lowerLimit;
        // cout<<"Numero a ser inserido: "<<aux<<endl;
        insert(list, aux);
    }
}

// ------------------------------------------------------------
// Printing
void printRegistry(Registro aux){
    int i;

    cout<< "\nItens: \n"
        << "Chave: " << aux.chave << "\n";
    for(i=0; i<10; i++)
        cout<< "Nome " << i << ": " << aux.nomes[i] << "\n";
    cout<< "Flag: " << aux.flag << "\n";
    for(i=0; i<4; i++)
        cout<< "Arr " << i << ": " << aux.arr[i] << "\n";
}

#endif