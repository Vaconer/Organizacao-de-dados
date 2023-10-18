#include <iostream>
// #include <fstream>
#include "..\lib\dataTypes.h"
#include "..\lib\merge.h"

using namespace std;

List t;
int *arr;

int main(int argv, char **argc){
    if(argv != 2){
        cout<< "Erro: argv different than expected (2)";
        return 0;
    }

    srand(time(0));
    // ofstream Arquivo("output.txt");

    int n = atoi(argc[1]);

    int com = 0; // n = 10000000;
    clock_t inicio, fim;
    unsigned long int tempo;

    start(t);

    fillList(t, n);
    arr = new int[n];

    cout<<"Lista criada\n";

    ListToArray(t, arr);

    // cout<< "List after conversion\n";
    // watch(t);

    inicio = clock();
    mergeSort(arr, 0, n, com);
    fim = clock();

    delete[] arr;

    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
    cout<< "Comparacoes: " << com <<"\n"
        << "Tempo gasto: " << tempo <<"\n";

    // Arquivo << "Comparacoes: " << com<<"\n"
    //             << "Tempo gasto: " << tempo<<"\n"
    //             << "-------------------------------------\n";

}
// comparacoes: 220100868