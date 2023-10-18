// Main file for cenario 1
#include ".\lib\dataTypes.h"
#include ".\lib\merge.h"
#include <fstream>

int* array;
Registro* registro;
List lista;

void Choice(int tam, string file, int choice){
    ofstream Arquivo(file);
    int comp, i;
    clock_t inicio, fim;
    unsigned long int tempo;

    Arquivo << "Item: ";
    if(choice == 1)
        Arquivo << "Vetor\n";
    else if(choice == 2)
        Arquivo << "Struct\n";
    else
        Arquivo << "Lista\n";
    
    Arquivo << "Numero de itens: " << tam <<"\n"
            << "Nome do Arquivo: " << file <<"\n"
            << "-------------------------------------\n";

    for(i=0; i<5; i++){
        comp = 0;

        if(choice == 1){        // Vetor
            array = new int[tam];
            fillArray(array, tam);

            cout<<"Array criado\n";

            inicio = clock();

            mergeSort(array, 0, tam, comp);

            fim = clock();
            cout<<"Array organizado\n";
            delete[] array;

        } else if(choice == 2){ // Struct
            registro = new Registro[tam];
            fillRegistry(registro, tam);

            cout<<"Struct criado\n";

            inicio = clock();

            mergeSortReg(registro, 0, tam, comp);

            fim = clock();
            cout<<"Struct organizado\n";
            delete[] registro;

        } else {                // Lista
            start(lista);
            fillList(lista, tam);

            cout<<"Lista criada\n";

            inicio = clock();

            lista.first = mergeSort(lista.first, comp);

            fim = clock();
            cout<<"Lista organizada\n";
            restart(lista);

        }

        tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;

        Arquivo << "Comparacoes: " << comp<<"\n"
                << "Tempo gasto: " << tempo<<"\n"
                << "-------------------------------------\n";

    }
}

// main.exe (1, 2 ou 3) (tam) (nome arquivo)
int main(int argv, char *argc[]){
    srand(time(0));

    if(argv != 4)
        printf("Erro: Argv number different than expected (4)\n");
    else {
        int DataType = atoi(argc[1]);
        int tam = atoi(argc[2]);
        string file = argc[3];

        Choice(tam, file, DataType);
    }

    return 0;
}