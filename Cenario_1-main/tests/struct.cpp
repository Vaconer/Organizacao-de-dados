#include <iostream>
#include "..\lib\dataTypes.h"
#include "..\lib\merge.h"

using namespace std;

int main(){
    Registro a[3];
    int i, comp;

    fillRegistry(a, 3);

    for(i=0; i<3; i++)
        printRegistry(a[i]);

    mergeSortReg(a, 0, 3, comp);

    cout<<"test3\n";

    for(i=0; i<3; i++)
        printRegistry(a[i]);
}